#include <iostream>

using namespace std;
class HasPtr {
    public :
    HasPtr(const string &s = string()):
        ps(new std::string(s)),i(0),use(new std::size_t(1)){}
    HasPtr(const HasPtr &p):
        ps(p.ps) ,i(p.i),use(p.use){
            ++*use;
        }

    HasPtr& operator=(const HasPtr&);
    ~HasPtr();
private :
    string *ps;
    int i;
    size_t *use;
};