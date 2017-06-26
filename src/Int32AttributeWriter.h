#ifndef __INT32_ATTRIBUTE_WRITER_H__
#define __INT32_ATTRIBUTE_WRITER_H__

#include "AttributeWriter.h"

class Int32AttributeWriter:public AttributeWriter  {
public:
    Int32AttributeWriter() { }
    Int32AttributeWriter(int _maxDocNum):maxDocNum(_maxDocNum), docNum(0), data(NULL) {}

    virtual ~Int32AttributeWriter();

    bool init(const std::string &_attrName);

    int addField(int docid, std::string &value);

    virtual void print();
private:
    std::string attrName;
    int maxDocNum;
    int docNum;
    int32_t *data;
};

#endif
