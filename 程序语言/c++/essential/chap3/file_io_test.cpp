#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    string s;
    vector<string> vs;
    while(cin>>s)
        vs.push_back(s);
    for (auto i = vs.begin(); i != vs.end();++i)
    {
        cout << *i << endl;
    }

    for(auto j : vs)
    {
        cout << j << endl;
    }
    return 0;
}