#include <bits/stdc++.h>

using std::find;
using std::map;
using std::max;
using std::vector;

class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        int size = nums.size();
        int maxn = 0;
        map<int, int> times;
        int degree = 0;

        for (int i = 0; i < size; ++i)
        {
            maxn = max(++times[nums[i]], maxn);
        }
        if (maxn == 1)
            return 1;
        for (auto &item : times)
        {
            if (item.second == maxn)
            {
                degree = max((int)((find(nums.begin(), nums.end(), item.first) - nums.begin()) + (find(nums.rbegin(), nums.rend(), item.first) - nums.rbegin())), degree);
            }
        }

        return size - degree;
    }
};
