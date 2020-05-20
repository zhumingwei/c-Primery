#include "HasPrt.h"

HasPtr& HasPtr::operator=(const HasPtr &rhs){
    //todo
    ++*rhs.use;
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

HasPtr::~HasPtr()
{
    if(--*use == 0){
        delete ps;
        delete use;
    }
}