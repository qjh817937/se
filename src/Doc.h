#ifndef __DOC_H__
#define __DOC_H__

#include <string>
#include <list>

struct Field {
    Field(const std::string &_name,
        const std::string &_value):name(_name),value(_value) { }
    std::string name;
    std::string value;
};

class Doc {
public:
    Doc():docid(-1) { }
    virtual ~Doc() { }

public:
    int docid;
    std::string pk;
    std::list<Field> indexFields;
    std::list<Field> attrFields;
};

#endif
