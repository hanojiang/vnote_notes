#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    // string s;
    // vector<string> vs;
    // while(cin>>s)
    //     vs.push_back(s);
    // for (auto i = vs.begin(); i != vs.end();++i)
    // {
    //     cout << *i << endl;
    // }

    // for(auto j : vs)
    // {
    //     cout << j << endl;
    // }

    vector<int> a(5,1);
    int len = a.size();
    int b[len];
    for (int i = 0; i < len; i++) {
        b[i]=i;
        cout << b[i] << endl;
    }

    return 0;
}