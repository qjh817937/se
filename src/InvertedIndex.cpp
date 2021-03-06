
#include <iostream>
#include <InvertedIndex.h>

using namespace std;

int InvertedIndex::add(const string &term, int docId) {
    int offset = dict.find(term);
    if (offset < 0) {
        // postfile add
        offset = postlistFile.add();
        // dict add
        dict.add(term, offset);
    }
    
    //  postfile add docid
    int ret = postlistFile.append(offset, docId);
    return ret;
}

int InvertedIndex::find(const string &term, Postlist &postlist) {
    int offset = dict.find(term);
    if (offset < 0) {
        cerr << "term: " << term << " not exist" << endl;
        return -1;
    }
    cerr << "InvertedIndex::find term: " << term << " offset:"  << offset << endl;

    int ret = postlistFile.find(offset , postlist);
    if (ret < 0) {
        cerr << "find postlit by offset:" << offset << " failed" << endl;
        return -1;
    }
    return 0;
}

void InvertedIndex::print() {
    printf("index:%s\n", indexName.c_str());
    map<string, int> &term2offset = dict.getTerm2offset();
    for(map<string, int>::iterator it = term2offset.begin();
        it != term2offset.end();
        it++) {
        string indexValue = it->first;
        int offset = it->second;

        Postlist postlist;
        int ret = postlistFile.find(offset , postlist);
        printf("  term:%s docids:", indexValue.c_str());
        for(int i = 0; i< postlist.size(); i++) {
            printf("%d ", postlist[i]);
        }
        printf("\n");
    }
}
