#include <iostream>
#include "src/StrVec.h"

int main(int, char**) {
    std::cout << "Hello, world!\n";
    StrVec sv;
    sv.push_back("1");
    sv.push_back("1");
    sv.push_back("1");
    sv.push_back("1");
    sv.push_back("1");
    sv.push_back("1");
    sv.push_back("1");
    sv.push_back("1");
    sv.push_back("1");
    sv.size();
    StrVec sv1 = sv;
    sv.operator==(sv1);
    
}
