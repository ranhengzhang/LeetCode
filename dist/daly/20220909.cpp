#include <bits/stdc++.h>

using std::max;
using std::string;
using std::vector;

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int step = 0;
        int size = logs.size();

        for (int i = 0; i < size; ++i)
        {
            if (logs[i] == "../")
            {
                if (step)
                    --step;
            }
            else if (logs[i] != "./")
            {
                ++step;
            }
        }

        return step;
    }
};
