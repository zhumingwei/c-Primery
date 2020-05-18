
#include <iostream>
#include <fstream>
#include "main.h"
#include "src/text_query.h"
#include "src/query_result.h"
using namespace std;


int main(int argc, char const *argv[])
{
    string s = "/Volumes/My Passport/project/MyProject/c++/c-Primery/query_process/myfile";
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
        print(cout, tq.query(s)) << endl;
    }
}
