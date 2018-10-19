//n(3n-1)/2
#include "pentagonal_array.h"
#include <iostream>
using namespace std;

const vector<int> *PentagalSeq(int size)
{
    const int kNumberMax = (int)(sqrt(1 + 4.0 * 3 * 2 * INT_MAX) + 1) / 6.0;
    static vector<int> seq;
    if(!IsSizeOk(size))
        return 0;

    if (seq.size() > 0)
    {
        cout << "vector is enough, without creat"<<endl;
        return &seq;
    }
    else
    {
        cout << "vector is empty, created" << endl;
        for (int i = 0; i < kNumberMax; i++)
        {
            seq.push_back(i * (3 * i - 1) / 2);
        }
    }
    return &seq;
}
void DisplaySeqElement(const vector<int> *seq, int display_size)
{
    if (display_size > seq->size())
    {
        cout << "display size is biger then array size" << endl;
    }
    else
    {
        for (int i = 0; i < display_size; i++)
            cout << "the "<<i+1<<"th is "<<(*seq)[i + 1] << endl; //取值运算符优先级低于[],所以要加上括号
    }
}

int main(int argc, char const *argv[])
{
    const vector<int> *pen_seq = PentagalSeq(1000);
    // cout << pen_seq->size() << endl;
    DisplaySeqElement(pen_seq,20);
    const vector<int> *pen_seq1 = PentagalSeq(200);
    DisplaySeqElement(pen_seq1,20);
    system("pause");
    return 0;
}
