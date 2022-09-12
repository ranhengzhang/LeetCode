#include <bits/stdc++.h>

using std::greater;
using std::sort;
using std::vector;

class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());

        int size = nums.size();

        nums.push_back(-1);
        for (int i = 1; i <= size; ++i)
        {
            if (i <= nums[i - 1] && i > nums[i])
            {
                return i;
            }
        }

        return -1;
    }
};
