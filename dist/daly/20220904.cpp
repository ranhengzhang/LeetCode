#include <bits/stdc++.h>

using std::vector;

class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int rows = mat.size(), cols = mat[0].size();
        int count, last, sum = 0;

        for (int i = 0; i < rows; ++i)
        {
            count = 0;
            last = -1;
            for (int j = 0; j < cols; ++j)
            {
                count += mat[i][j];
                if (mat[i][j])
                {
                    last = j;
                }
            }
            if (count == 1)
            {
                count = 0;
                for (int j = 0; j < rows; ++j)
                {
                    count += mat[j][last];
                }
                sum += count == 1;
            }
        }

        return sum;
    }
};
