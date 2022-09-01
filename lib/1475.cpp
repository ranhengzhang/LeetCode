#include <bits/stdc++.h>

using std::vector;

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        int size = prices.size();

        for (int i = 0; i < size; ++i)
        {
            int rebate = 0;

            for (int j = i + 1; j < size; ++j)
            {
                if (prices[j] <= prices[i])
                {
                    rebate = prices[j];
                    break;
                }
            }
            prices[i] -= rebate;
        }

        return prices;
    }
};
