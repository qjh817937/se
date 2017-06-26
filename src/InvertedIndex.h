#ifndef __INVERTEDINDEX_H__
#define __INVERTEDINDEX_H__

#include <string>
#include "Dictionary.h"
#include "PostlistFile.h"

class InvertedIndex {
public:
    InvertedIndex() { }
    virtual ~InvertedIndex() { }

    bool init(const std::string &_indexName) { indexName = _indexName; }

    int add(const std::string &term, int docId);
    
    int find(const std::string &term, Postlist &postlist);

    void print();
private:
    std::string indexName;
    Dictionary dict;
    PostlistFile postlistFile;
};

#endif
