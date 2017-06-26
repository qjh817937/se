#ifndef __INDEX_WRITER_H__
#define __INDEX_WRITER_H__

#include <map>
#include <Doc.h>
#include "DocidManager.h"
#include "InvertedIndex.h"
#include "AttributeWriter.h"

class IndexWriter {
public:
    IndexWriter():docidManager(NULL),ivtIndexs(NULL),attrWriters(NULL) {} 

    bool init();
    int add(Doc &doc);


    // test
    int find(const std::string &indexName, const std::string &term);
    void print();
    void print(const std::string &indexName, 
        const std::string &indexValue,
        Postlist &postlist);

private:
    DocidManager *docidManager;
    std::map<std::string, InvertedIndex*> *ivtIndexs; // indexname->index
    std::map<std::string, AttributeWriter*>  *attrWriters; // fieldname->...
};
#endif
