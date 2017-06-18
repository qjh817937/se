#ifndef __INDEX_WRITER_H__
#define __INDEX_WRITER_H__

#include <map>
#include <Doc.h>
#include <DocidManager.h>
#include <InvertedIndex.h>
//#include <Attribute.h>

class IndexWriter {
public:
    IndexWriter(DocidManager *_docidManager, std::map<std::string, InvertedIndex> *_ivtIndexs): 
            docidManager(_docidManager), ivtIndexs(_ivtIndexs) { }

    int add(Doc &doc);


    // test
    int find(const std::string &indexName, const std::string &term);
    void print(const std::string &indexName, 
        const std::string &indexValue,
        Postlist &postlist);

private:
    DocidManager *docidManager;
    std::map<std::string, InvertedIndex> *ivtIndexs; // indexname->index
    //std::map<std::string, Attribute>  *attributes; // fieldname->...
};
#endif
