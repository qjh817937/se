#include <Dictionary.h>
using namespace std;

bool Dictionary::add(const string &term, int offset) {
    map<string, int>::iterator it = term2offset.find(term);
    if (term2offset.end() != it) { // exist
        return -1;
    }
    term2offset.insert(make_pair(term, offset));
    return 0;
}

int Dictionary::find(const string &term) {
    map<string, int>::iterator it = term2offset.find(term);
    if (term2offset.end() != it) { // exist
        return it->second;
    }
    return -1;
}

int Dictionary::dump(string &path) {
    return 0;
}

int Dictionary::load(string &path) {
    return 0;
}
