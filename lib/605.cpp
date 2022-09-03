#include <bits/stdc++.h>

using std::vector;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int size = flowerbed.size();
        int plant = 0;

        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.insert(flowerbed.end(), 0);
        for (int i = 1; i <= size; ++i)
        {
            if (!flowerbed[i] && !(flowerbed[i - 1] || flowerbed[i + 1]))
            {
                ++plant;
                flowerbed[i] = 1;
            }
        }

        return plant >= n;
    }
};
