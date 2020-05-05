#include <iostream>

struct Sales_data
{
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&); //将一个Sales_data夹袄另一个上
    double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;//销量
    double revenue = 0.0;//收益
};
//Sales_data 的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream& , const Sales_data&);
std::istream &read(std::istream, Sales_data&);

