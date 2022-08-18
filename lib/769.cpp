#include <bits/stdc++.h>

using std::vector;

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int block = 0, maxNum = 0;
        int size = arr.size();

        for (int i = 0; i < size; ++i)
        {
            if (arr[i] > maxNum)
                maxNum = arr[i];
            if (i == maxNum)
            {
                ++block;
            }
        }

        return block;
    }
};
