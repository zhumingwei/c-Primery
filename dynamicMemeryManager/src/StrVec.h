
#ifndef STRVEC_H
#define STRVEC_H
#include <iostream>
using namespace std;

class StrVec {
public :
    StrVec():
        elements(nullptr), first_free(nullptr), cap(nullptr){}
    StrVec(const StrVec&);
    StrVec &operator=(const StrVec&);

    StrVec(StrVec &&s) noexcept;


    ~StrVec();
    void push_back(const std::string&);
    size_t size() const {return first_free - elements ;}
    size_t capacity() const {return cap - elements;}
    std::string *begin() const {return elements; }
    std::string *end() const {return first_free;}

private :
    std::allocator<std::string> alloc;
    void chk_n_alloc()
        {if (size() == capacity()) reallocate();}
    std::pair<string*, string*> alloc_n_copy
        (const string*,const string*);
    void free(); //销毁元素并释放内存
    void reallocate(); // 活的更多内存并拷贝已有内存
    string *elements; // 指向数组首元素的指针
    string *first_free;// 指向数组第一个空闲元素的指针
    string *cap; //指向数组尾喉位置的指针
};

#endif