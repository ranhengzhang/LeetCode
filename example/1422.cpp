#include <bits/stdc++.h>

using std::string;

class Solution
{
public:
    int maxScore(string s)
    {
        int num0 = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                num0++;
        }
        int re = 0;
        int left_0 = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == '0')
            {
                left_0++;
            }
            int tmp = left_0 + s.size() - i - 1 - (num0 - left_0);
            re = tmp > re ? tmp : re;
        }
        return re;
    }
};
