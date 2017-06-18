#ifndef __POSTLISTFILE_H__
#define __POSTLISTFILE_H__

#include <vector>
#include <map>

typedef std::vector<int> Postlist;
typedef std::map<int, Postlist> Postlists;

class PostlistFile {
public:
    PostlistFile() { }
    virtual ~PostlistFile() { }

    int add();

    int append(int offset, int docid);

    int find(int offset, Postlist &postlist);
private:
    Postlists postlists;
};


#endif
