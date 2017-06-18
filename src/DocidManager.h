#ifndef __DOCID_MANAGER_H__
#define __DOCID_MANAGER_H__

#include <string>
#include <map>

class DocidManager {
public:
    DocidManager() { }
    virtual ~DocidManager() { }

    int getDocid(const std::string &pk) {
        std::map<std::string, int>::iterator it = docids.find(pk);
        if (docids.end() != it) { 
            return it->second;
        }

        int docid = (int)docids.size();
        docids.insert(make_pair(pk, docid));
        return docid;
    };

private:
    std::map<std::string, int> docids;
};

#endif
