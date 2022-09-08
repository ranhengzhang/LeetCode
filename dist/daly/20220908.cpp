#include <bits/stdc++.h>

using std::min;
using std::vector;

class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> answer(n);

        answer[0] = 1;
        answer[1] = k + 1;
        for (int i = 2; i <= k; ++i)
        {
            answer[i] = (i & 1) ? answer[i - 2] - 1 : answer[i - 2] + 1;
        }
        for (int i = ++k; i < n; ++i)
        {
            answer[i] = i + 1;
        }

        return answer;
    }
};
