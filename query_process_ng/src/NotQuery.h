//
// Created by zhumingwei on 2020/5/27.
//

#ifndef QUERY_PROCESS_NG_NOTQUERY_H
#define QUERY_PROCESS_NG_NOTQUERY_H


#include "Query_base.h"
#include "Query.h"
class NotQuery : public Query_base{
    friend Query operator~(const Query &);
    NotQuery(const Query &q):query(q){ }
    std::string rep() const override{
        return "~(" + query.rep() + ")";
    }
    QueryResult eval(const TextQuery &) const override;
    Query query;
};

#endif //QUERY_PROCESS_NG_NOTQUERY_H
