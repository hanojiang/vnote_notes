#ifndef PENTAGONAL_ARRAY_H
#define PENTAGONAL_ARRAY_H

#include <vector>
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;
const vector<int> *PentagalSeq(int size);
void DisplaySeqElement(const vector<int> *seq);

inline bool IsSizeOk(int size)
{
    const int kNumberMax = (int)(sqrt(1 + 4.0 * 3 * 2 * INT_MAX) + 1) / 6.0;
    if (size < 0 || size > kNumberMax)
    {
        cout << "the number of vector is too max" << '\n';
        return false;
    }
    return true;
}
#endif /* end of include guard: PENTAGONAL_ARRAY_H */
