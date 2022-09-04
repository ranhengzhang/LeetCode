#include <bits/stdc++.h>

using std::vector;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        long square = 0;
        int decrease = 0;
        int size = nums.size();

        for (int i = 0; i < size; ++i)
        {
            square += nums[i] * nums[i] - (i + 1) * (i + 1);
            decrease += nums[i] - i - 1;
        }

        int increase = square / decrease;

        return vector<int>{(increase + decrease) / 2, (increase - decrease) / 2};
    }
};
