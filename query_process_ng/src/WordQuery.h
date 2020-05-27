//
// Created by zhumingwei on 2020/5/27.
//

#ifndef QUERY_PROCESS_NG_WORDQUERY_H
#define QUERY_PROCESS_NG_WORDQUERY_H


#include <iostream>
#include "Query_base.h"
#include "text_query.h"
#include "query_result.h"
#include "Query.h"

class WordQuery : public Query_base{
    friend class Query;

    WordQuery(const std::string &s):query_word(s){}

    QueryResult eval(const TextQuery &t) const override {
        std::string str(query_word);
        return t.query(str);
    };

    std::string rep() const override{
        return query_word;
    }

    std::string query_word;
};

#endif //QUERY_PROCESS_NG_WORDQUERY_H
