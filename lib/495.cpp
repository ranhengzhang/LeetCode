#include <bits/stdc++.h>

using std::vector;

class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int size = timeSeries.size();
        int end = -1;
        int sum = 0;

        for (int i = 0; i < size; ++i)
        {
            sum += duration;
            if (timeSeries[i] <= end)
            {
                sum -= end - timeSeries[i] + 1;
            }
            end = timeSeries[i] + duration - 1;
        }

        return sum;
    }
};
