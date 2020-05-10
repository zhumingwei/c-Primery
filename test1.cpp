// #include <string.h>
#include <iostream>
#include <vector>
using std::string;
using std::cout;
using std::endl;
using std::vector;
using namespace std;
int main(int argc, char const *argv[])
{
    int i =1,j=2;
    double slope = static_cast<double>(j) /i;
    cout <<slope;

    
}

class Account {
    public :
        void calculate() {
            amount += amount * interestRate;
        }
        static double rate() { return interestRate ;}
        static void rate(double);
        
    private :
        std::string owner;
        double amount;
        static double interestRate;
        static double initRate();
};

void Account::rate(double newRate){
    interestRate = newRate;
}

class Example {
    public :
    static double rate;
    static const int vecsize = 20;
    static vector<double> vec(int);
};

double Example::rate;
vector<double> Example::vec(int v){
    rate = v;
}