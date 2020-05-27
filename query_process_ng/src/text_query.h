#ifndef TEXT_QUERY
#define TEXT_QUERY
#include <vector>
#include <map>
#include <set>

using namespace std;
class QueryResult;
class TextQuery
{
public:

    using line_no = vector<string>::size_type;
    TextQuery(ifstream &);
    QueryResult query(const string &) const;
private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};
#endif