#ifndef UNTITLED_QUERYRESULT_H
#define UNTITLED_QUERYRESULT_H

#include <iostream>
#include <set>
#include "text_query.h"

using namespace std;

class QueryResult
{

    friend std::ostream &print(std::ostream &, const QueryResult &);

public:
    QueryResult(std::string s,
                std::shared_ptr<set<TextQuery::line_no>> p,
                shared_ptr<vector<string>> f) : sought(s), lines(p), file(f){

    };

private:
    string sought;                             //查询的单词
    shared_ptr<set<TextQuery::line_no>> lines; //出现的行号
    shared_ptr<vector<string>> file;           //输出文件
};

string make_plural(size_t ctr,const string &word, const string &ending);
#endif