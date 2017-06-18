#include <IndexWriter.h>
#include <list>
#include <iostream>

using namespace std;

int IndexWriter::add(Doc &doc) {
    // get docid
    int docid = docidManager->getDocid(doc.pk);
    
    // write inverted index
    for (list<Field>::iterator it = doc.indexFields.begin();
        it != doc.indexFields.end();
        it++) {
            string indexName = it->name;
            string indexValue = it->value;
            InvertedIndex &index = (*ivtIndexs)[indexName];
            index.add(indexValue, docid);
    }

    return 0;
}

int IndexWriter::find(const string &indexName, const string &indexValue) {
    map<string, InvertedIndex>::iterator it = ivtIndexs->find(indexName);
    if (ivtIndexs->end() == it) {
        cerr << "index:" << indexName << " not exist" << endl;
        return -1;
    }

    InvertedIndex &index = it->second;
    Postlist postlist;
    index.find(indexValue, postlist);

    // print
    print(indexName, indexValue, postlist);
    return 0;
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

