#include <stdio.h>
#include <string>
#include <PostlistFile.h>
#include <InvertedIndex.h>
#include <IndexWriter.h>

using namespace std;

int main(int argc, char** args) {
    Doc doc1;
    doc1.pk = "0000";
    doc1.indexFields.push_back(Field("index1", "aaa"));
    doc1.indexFields.push_back(Field("index1", "bbb"));

    Doc doc2;
    doc2.pk = "1111";
    doc2.indexFields.push_back(Field("index1", "aaa"));
    doc2.indexFields.push_back(Field("index1", "ccc"));

    DocidManager docidManager;
    map<string, InvertedIndex> ivtIndexs;
    IndexWriter indexWriter(&docidManager, &ivtIndexs);
    indexWriter.add(doc1);
    indexWriter.add(doc2);

    indexWriter.find("index1", "aaa");

    return 0;
}
