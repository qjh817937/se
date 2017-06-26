#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <string>
#include <map>

class Dictionary {
public:
    Dictionary() { }

    virtual ~Dictionary() { }

    bool add(const std::string &term, int offset);

    /**
     *
     */
    int find(const std::string &term);

    /**
     *
     *
     */
    int dump(std::string &path);

    /**
     *
     */
    int load(std::string &path);

    std::map<std::string, int>& getTerm2offset() { 
        return term2offset;
    }
private:
    std::map<std::string, int> term2offset;

    /**
     *
     */
};

#endif
