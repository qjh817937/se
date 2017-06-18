#ifndef __INVERTEDINDEX_H__
#define __INVERTEDINDEX_H__

#include <Dictionary.h>
#include <PostlistFile.h>

class InvertedIndex {
public:
    InvertedIndex() { }
    virtual ~InvertedIndex() { }

    int add(const std::string &term, int docId);
    
    int find(const std::string &term, Postlist &postlist);
private:
    Dictionary dict;
    PostlistFile postlistFile;
};

#endif
