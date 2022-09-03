#include <bits/stdc++.h>

using std::max;
using std::sort;
using std::vector;

class Solution
{
private:
    bool static cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }

public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int maxl = 0;
        int maxn = 0;
        int size = pairs.size();

        sort(pairs.begin(), pairs.end(), this->cmp);
        for (int i = 0; i < size; ++i)
        {
            if (pairs[i][0] > maxn) {
                ++maxl;
                maxn = pairs[i][1];
            }
        }

        return maxl;
    }
};
