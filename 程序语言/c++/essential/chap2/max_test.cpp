#include <iostream>
#include <string>
using namespace std;

int max(int number_a, int number_b)
{
    return number_a > number_b ? number_a : number_b;
}
double max(double number_a,double number_b)
{
    return number_a > number_b ? number_a : number_b;
}

const string & max(const string& str_a,const string& str_b)
{
    return str_a > str_b ? str_a : str_b;
}

int main(int argc, char const *argv[]) {
    int a = max(3, 4);
    cout << a << endl;
    string str_a = "hello";
    string str_b = "hellp";
    const string &r_str = max(str_a, str_b);
    cout << r_str << endl;

    system("pause");
    return 0;
}