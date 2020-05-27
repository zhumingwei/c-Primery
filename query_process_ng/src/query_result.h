#ifndef UNTITLED_QUERYRESULT_H
#define UNTITLED_QUERYRESULT_H

#include <iostream>
#include <set>
#include "text_query.h"
#include "memory"

using namespace std;

class QueryResult {

    friend std::ostream &print(std::ostream &, const QueryResult &);
public:
    QueryResult(string s,
                shared_ptr<set<TextQuery::line_no>> p,
                shared_ptr<vector<string>> f) :
            sought(s), lines(p), file(f) {
    };
    std::set<TextQuery::line_no>::iterator begin() const { return lines->begin(); }
    std::set<TextQuery::line_no>::iterator end() const { return lines->end(); }
    // std::shared_ptr<StrBlob> get_file() const { return std::make_shared<StrBlob>(file); }

    shared_ptr<vector<std::string>> get_file(){
        return std::make_shared<std::vector<std::string>>(*file);
    }


private:
    string sought;                             //查询的单词
    shared_ptr<set<TextQuery::line_no>> lines; //出现的行号
    shared_ptr<vector<string>> file;           //输出文件
};

string make_plural(size_t ctr, const string &word, const string &ending);

#endif