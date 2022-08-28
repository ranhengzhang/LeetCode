#include <bits/stdc++.h>

class Solution
{
public:
    int trailingZeroes(long long n)
    {
        int k = 0;
        while (n != 0)
        {
            k += n / 5;
            n /= 5;
        }
        return k;
    }
    int preimageSizeFZF(int k)
    {
        long long bottom = 0, front = (long long)k * 5, middle = (bottom + front) / 2;

        while (bottom < front)
        {
            long long zeros = this->trailingZeroes(middle);

            if (zeros == k)
                break;
            else if (zeros < k)
            {
                bottom = middle + 1;
            }
            else
            {
                front = middle;
            }
            middle = (bottom + front) / 2;
        }

        return this->trailingZeroes(middle) == k ? 5 : 0;
    }
};
