#include <bits/stdc++.h>

using std::max;
using std::vector;

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int top = -1;
        for (auto a : arr)
        {
            int maxv = a;
            while (top >= 0 && arr[top] > a)
                maxv = max(maxv, arr[top--]);

            arr[++top] = maxv;
        }
        return top + 1;
    }
};
