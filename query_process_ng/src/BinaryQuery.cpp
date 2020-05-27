//
// Created by zhumingwei on 2020/5/27.
//

#include "BinaryQuery.h"
#include "query_result.h"

QueryResult OrQuery::eval(const TextQuery & text) const {
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>(left.begin(),left.end());
    ret_lines->insert(right.begin(),right.end());
    return QueryResult(rep(),ret_lines,left.get_file());
}

QueryResult AndQuery::eval(const TextQuery & text) const {
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    set_intersection(left.begin(),left.end(),right.begin(),right.end(),inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

Query operator|(const Query& lhs,const Query& rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}

Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}