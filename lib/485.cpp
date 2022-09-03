#include <bits/stdc++.h>

using std::max;
using std::vector;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int size = nums.size();
        int sum = 0;
        int maxn = 0;

        for (int i = 0; i < size; ++i)
        {
            if (nums[i] == 0)
            {
                maxn = max(maxn, sum);
                sum = 0;
            }
            else
            {
                ++sum;
            }
        }
        maxn = max(maxn, sum);

        return maxn;
    }
};
