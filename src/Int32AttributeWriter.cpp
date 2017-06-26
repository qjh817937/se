#include "Int32AttributeWriter.h"

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

Int32AttributeWriter::~Int32AttributeWriter() {
    if (NULL != data) {
        delete data;
        data = NULL;
    }
}
bool Int32AttributeWriter::init(const string &_attrName) {
    attrName = _attrName;
    if (NULL == data) {
        data = (int32_t*) malloc(sizeof(int32_t)*maxDocNum);
    }
}

int Int32AttributeWriter::addField(int docid, string &value) {
    if (docid >= maxDocNum) {
        cerr << "docid: " << docid << " invalid, maxdocnum:" << maxDocNum << endl;
        return -1;
    }

    // stirng 2 int
    int ivalue = atoi(value.c_str());
    cout << "docid:" << docid << " attr value:" << ivalue << endl;
    data[docid] = ivalue;
    docNum++;
    return 0;
}

void Int32AttributeWriter::print() {
    printf("attr:%s\n", attrName.c_str());
    printf("  docid:");
    for (int i = 0; i < docNum; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    
    printf("  value:");
    for (int i = 0; i < docNum; i++) {
        printf("%2d ", data[i]);
    }
    printf("\n");
}

