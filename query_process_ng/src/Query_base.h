//
// Created by zhumingwei on 2020/5/27.
//

#ifndef QUERY_PROCESS_NG_QUERY_BASE_H
#define QUERY_PROCESS_NG_QUERY_BASE_H


#include "text_query.h"

class Query_base {
    friend class Query;

protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;

private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual std::string rep() const = 0;
};


#endif //QUERY_PROCESS_NG_QUERY_BASE_H


