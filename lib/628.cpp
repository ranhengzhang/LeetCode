#include <bits/stdc++.h>

using std::max;
using std::vector;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int size = nums.size();

        if (size == 3)
        {
            return nums[0] * nums[1] * nums[2];
        }
        else
        {
            int lst[] = {1001, 1001, -1001, -1001, -1001};

            for (int i = 0; i < size; ++i)
            {
                if (nums[i] > lst[4])
                {
                    lst[2] = lst[3];
                    lst[3] = lst[4];
                    lst[4] = nums[i];
                }
                else if (nums[i] > lst[3])
                {
                    lst[2] = lst[3];
                    lst[3] = nums[i];
                }
                else if (nums[i] > lst[2])
                {
                    lst[2] = nums[i];
                }
                if (nums[i] < lst[0])
                {
                    lst[1] = lst[0];
                    lst[0] = nums[i];
                }
                else if (nums[i] < lst[0])
                {
                    lst[1] = nums[i];
                }
            }

            return max(lst[2] * lst[3] * lst[4], lst[4] * lst[0] * lst[1]);
        }
    }
};
