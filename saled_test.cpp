#include <iostream>

using namespace std;
class Sales_data
{
    //友元
    friend istream &read(std::istream &, Sales_data &);
    friend ostream &print(std::ostream &os, const Sales_data &item);
public:
    //新增的构造函数
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n){};
    Sales_data(std::istream &);
    std::string isbn() const { return this->bookNo; }
    Sales_data &combine(const Sales_data &); //将一个Sales_data夹袄另一个上

    double avg_price() const;
private :
    std::string bookNo;
    unsigned units_sold = 0; //销量
    double revenue = 0.0;    //收益
};
//Sales_data 的非成员接口函数
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
// std::istream &read(std::istream &, Sales_data &);

double Sales_data::avg_price() const
{
    if (units_sold)
    {
        return revenue / units_sold;
    }
    else
    {
        return 0;
    }
}

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.units_sold;
    return *this;
}


istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data::Sales_data(std::istream &is)
{
    read(is, *this);
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}


int main(int argc, char const *argv[])
{
    Sales_data sd(cin);
    cout << sd.avg_price() << endl;
    return 0;
}
