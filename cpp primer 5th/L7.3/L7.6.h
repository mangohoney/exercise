#ifndef L7_11_H
#define L7_11_H

#include <string>
#include <iostream>

using namespace std;

struct Sales_data
{
    Sales_data() = default;
    Sales_data(const string &s): bookNo(s) { }
    Sales_data(const string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(n * p) { }
    Sales_data(istream &)

    string isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data::Sales_data(istream &is)
{
    read(is, *this);
}
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.units_sold;
    return *this;
}

istream &read(istream &is, Sales_data &item)
{
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, Sales_data &item)
{
    os << item.bookNo << " " << item.units_sold << " " << item.revenue << endl;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

#endif // SALES_DATA_H
