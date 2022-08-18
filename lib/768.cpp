#include <bits/stdc++.h>

using std::vector;
using std::stack;

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int maxNum = arr.front(), minNum = arr.front();
        int size = arr.size();
        stack<int> maxStack;

        for (int i = 0; i < size; ++i)
        {
            if (arr[i] >= maxNum)
            {
                maxStack.push(maxNum);
                minNum = maxNum;
                maxNum = arr[i];
            }
            if (arr[i] < minNum)
            {
                while (!maxStack.empty() && arr[i] < maxStack.top())
                    maxStack.pop();
                if (maxStack.empty())
                    maxStack.push(arr[i]);
                minNum = maxStack.top();
            }
        }

        return maxStack.size();
    }
};
