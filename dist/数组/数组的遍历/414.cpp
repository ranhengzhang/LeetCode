#include <bits/stdc++.h>

using std::greater;
using std::sort;
using std::vector;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        vector<long> res(3, LONG_MIN);

        for (int item : nums)
        {
            if (item > res[0])
            {
                res[2] = res[1];
                res[1] = res[0];
                res[0] = item;
            }
            else if (item > res[1] && item < res[0])
            {
                res[2] = res[1];
                res[1] = item;
            }
            else if (item > res[2] && item < res[1])
            {
                res[2] = item;
            }
        }

        return res[2] == LONG_MIN ? res[0] : res[2];
    }
};
