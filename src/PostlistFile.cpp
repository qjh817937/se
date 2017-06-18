#include <PostlistFile.h>

#include <iostream>
using namespace std;

int PostlistFile::add() {
    int offset = (int) postlists.size();
    postlists.insert(make_pair(offset, vector<int>()));
    return offset;
}

int PostlistFile::append(int offset, int docid) {
    Postlists::iterator it = postlists.find(offset);
    if (postlists.end() == it) {
        cerr << "offset:" << offset << " not exist" << endl;
        return -1;
    }

    Postlist &postlist = it->second;
    postlist.push_back(docid);
    cerr << "offset:" << offset << ", docid:" << docid << endl;
    return 0;
}

int PostlistFile::find(int offset, Postlist &postlist) { // todo: copy
    Postlists::iterator it = postlists.find(offset);
    if (postlists.end() == it) {
        cerr << "offset:" << offset << " not exist" << endl;
        return -1;
    }

    postlist = it->second;
    return 0;
}
