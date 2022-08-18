#include <bits/stdc++.h>

using std::string;

class Solution
{
public:
    int maxScore(string s)
    {
        int sum = s.back() == '0' ? 0 : 1, max = -1, current = 0;
        int i = -1;
        int size = s.size() - 1;

        while (++i < size)
        {
            if (s[i] == '0')
            {
                current += 1;
                if (current > max)
                    max = current;
            }
            else
            {
                sum += 1;
                current -= 1;
            }
        }
        return sum + max;
    }
};
