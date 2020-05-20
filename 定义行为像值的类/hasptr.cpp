#include "hasptr.h"

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new string(*rhs.ps);//拷贝底层string
    delete ps; //释放旧内存
    ps = newp;
    i = rhs.i;
    return *this;
}