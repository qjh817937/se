#include "IndexWriter.h"

#include <list>
#include <iostream>

#include "Int32AttributeWriter.h"

using namespace std;

bool IndexWriter::init() {
    docidManager = new DocidManager();
    ivtIndexs = new map<string, InvertedIndex*>();
    attrWriters = new map<string, AttributeWriter*>();
    // 
    InvertedIndex *index = new InvertedIndex();
    index->init("index1");
    ivtIndexs->insert(make_pair("index1", index));

    // todo: attbite config
    Int32AttributeWriter *attrWriter = new Int32AttributeWriter(32);
    attrWriter->init("attr_1_int32");
    attrWriters->insert(make_pair("attr_1_int32", attrWriter));
    return true;
}

int IndexWriter::add(Doc &doc) {
    // get docid
    int docid = docidManager->getDocid(doc.pk);
    
    // write inverted index
    for (list<Field>::iterator it = doc.indexFields.begin();
        it != doc.indexFields.end();
        it++) {
        string indexName = it->name;
        string indexValue = it->value;
        map<string, InvertedIndex*>::iterator it = ivtIndexs->find(indexName);
        if (it == ivtIndexs->end()) {
            cerr << "index:" << indexName << " not exist" << endl;
            return -1;
        }
        InvertedIndex *index = it->second;
        index->add(indexValue, docid);
    }

    // attr 
    for (list<Field>::iterator it = doc.attrFields.begin();
        it != doc.attrFields.end();
        it++) {
        string attrName = it->name;
        string attrValue = it->value;
        map<string, AttributeWriter*>::iterator it = attrWriters->find(attrName);
        if (it == attrWriters->end()) {
            cerr << "attr:" << attrName << " writer not exist" << endl;
            return -1;
        }
        AttributeWriter *attrWriter =  it->second;
        attrWriter->addField(docid, attrValue);
    }
    return 0;
}

int IndexWriter::find(const string &indexName, const string &indexValue) {
    map<string, InvertedIndex*>::iterator it = ivtIndexs->find(indexName);
    if (ivtIndexs->end() == it) {
        cerr << "index:" << indexName << " not exist" << endl;
        return -1;
    }

    InvertedIndex *index = it->second;
    Postlist postlist;
    index->find(indexValue, postlist);

    // print
    print(indexName, indexValue, postlist);
    return 0;
}

void IndexWriter::print() {
    printf("----- print begin -----\n");
    map<string, InvertedIndex*>::iterator it = ivtIndexs->begin();
    for(; it != ivtIndexs->end(); it++) {
        const string &indexName = it->first;
        InvertedIndex *index = it->second;
        index->print();
    }

    map<string, AttributeWriter*>::iterator it2 = attrWriters->begin();
    for(; it2 != attrWriters->end(); it2++) {
        const string &attrName = it2->first;
        AttributeWriter *attrWriter = it2->second;
        attrWriter->print();
    }
    printf("----- print end -----\n");
}

void IndexWriter::print(const string &indexName,
    const string &indexValue, 
    Postlist &postlist) {
    printf("indexName:%s indexValue:%s, docids:",
        indexName.c_str(), indexValue.c_str());
    for (int i = 0; i < postlist.size(); i++) {
        printf("%d ", postlist[i]);
    }
}

