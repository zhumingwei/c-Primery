#include <iostream>
#include "main.h"
#include <fstream>
#include "src/text_query.h"
#include "src/Query.h"

using namespace std;


int main(int argc, char const *argv[])
{
    string s = "/Users/zhumingwei/Desktop/projecttemp/c-Primery/query_process_ng/myfile";//todo 本地绝对路径
    const char* path = s.c_str();
    ifstream fsobj(path,std::ifstream::in);
    if(!fsobj.good()){
        cout << "fs error" << endl;
        return 1;
    }
    runQueries(fsobj);
    return 0;
}

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);


    while (true)
    {
        cout << "enter word to look for , or q to quit";
        string s;
        if(!(cin >> s) || s == "q") break;
        Query query(s);
        Query query1("secretary");
        Query query2 = query & query1;

//        cout << query2.rep() << endl;

//        cout << query2 << endl;
        cout << ~query2 << endl;
        auto result = (~query2).eval(tq);
        print(cout, result ) << endl;
    }
}
