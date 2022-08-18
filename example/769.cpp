#include <bits/stdc++.h>

using std::vector;
using std::max;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int max_int = 0;
        int split = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            max_int = max(max_int, arr[i]);
            if (max_int == i)
                split++;
        }
        return split;
    }
};
