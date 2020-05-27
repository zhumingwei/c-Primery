//
// Created by zhumingwei on 2020/5/27.
//

#include "Query.h"
#include "WordQuery.h"

Query::Query(const string & s): q(new WordQuery(s)) {

}

std::ostream &operator<<(ostream &os, const Query &query) {
    os << query.rep() << endl;
    return os;
}
