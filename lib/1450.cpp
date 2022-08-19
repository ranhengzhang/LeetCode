#include <bits/stdc++.h>

using std::inner_product;
using std::plus;
using std::vector;

class Solution
{
public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime)
    {
        return inner_product(startTime.cbegin(), startTime.cend(), endTime.cbegin(), 0, plus<int>{}, [&](int a, int b)
                             { return a <= queryTime && b >= queryTime; });
    }
};
