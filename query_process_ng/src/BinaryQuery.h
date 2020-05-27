//
// Created by zhumingwei on 2020/5/27.
//

#ifndef QUERY_PROCESS_NG_BINARYQUERY_H
#define QUERY_PROCESS_NG_BINARYQUERY_H


#include "Query_base.h"
#include "Query.h"

class BinaryQuery : public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s) :
            lhs(l), rhs(r), opSym(s) {}

    std::string rep() const override{
        return "(" + lhs.rep() + " "
            + opSym + " "
            + rhs.rep() + ")";
    }

    Query lhs, rhs;

    std::string opSym;//运算符名字

};

class AndQuery: public BinaryQuery {
    friend Query operator&(const Query& lhs, const Query& rhs);
    AndQuery (const Query &left, const Query &right):
            BinaryQuery(left,right,"&"){ };
    QueryResult eval(const TextQuery &) const override;
};

class OrQuery: public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right):
        BinaryQuery(left, right, "|"){}
    QueryResult eval(const TextQuery &) const override;
};
#endif //QUERY_PROCESS_NG_BINARYQUERY_H
