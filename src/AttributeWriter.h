#ifndef __ATTRIBUGTE_WRITER__
#define __ATTRIBUGTE_WRITER__

#include <string>

class AttributeWriter{
public:
    AttributeWriter() {}
    virtual ~AttributeWriter() {}

    virtual int addField(int docid, std::string &value) = 0;

    virtual void print() = 0;
private:
};

#endif
