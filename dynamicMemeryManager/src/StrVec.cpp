#include "StrVec.h"

void StrVec::push_back(const string& s)
{
    chk_n_alloc();//确保有空间容纳新元素
    // 在 first_free 指向的元素中构造s 的副本
    alloc.construct(first_free ++,s); //这里会使用string的拷贝构造函数
}

pair<string* , string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
    // 分配空间保存给定范围中的元素
    auto data= alloc.allocate(e - b);
    return {data, uninitialized_copy(b ,e , data)}; // 最后一个构造元素之后的位置
}

void StrVec::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements;)
        {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() { free();}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
    //我们将分配当前大小两倍的内存空间
    auto newcapacity = size()? 2 * size() : 1;
    // 分配新内存
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;//指向新数组中下一个空闲位置
    auto elem = elements;//指向旧数组中下一个元素
    for (size_t i = 0; i < size(); i++)
    {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

StrVec::StrVec(StrVec &&s) noexcept: elements(s.elements), first_free(s.first_free), cap(s.cap)
    {
        s.elements = s.first_free = s.cap = nullptr;
    }

// StrVec &StrVec::operator=(StrVec &&rhs) 
// {
//     if(this != &rhs){
//         free();
//         elements = rhs.elements;
//         first_free = rhs.first_free;
//         cap = rhs.cap;
//         rhs.elements = rhs.first_free = rhs.cap = nullptr;
//     }

//     return *this;
// }