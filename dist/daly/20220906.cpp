#include <bits/stdc++.h>

using std::fill;
using std::string;

class Solution
{
public:
    int uniqueLetterString(string s)
    {
        int size = s.size();
        int leftIndex[size], rightIndex[size], lastIndex[26];
        long int ans = 0;

        fill(lastIndex, lastIndex + 26, -1);
        for (int i = 0; i < size; ++i)
        {
            int index = s[i] - 'A';

            leftIndex[i] = lastIndex[index];
            lastIndex[index] = i;
        }
        fill(lastIndex, lastIndex + 26, size);
        for (int i = size - 1; i >= 0; --i)
        {
            int index = s[i] - 'A';

            rightIndex[i] = lastIndex[index];
            lastIndex[index] = i;
        }
        for (int i = 0; i < size; ++i)
        {
            ans += (long long)(i - leftIndex[i]) * (long long)(rightIndex[i] - i);
        }

        return (int)ans;
    }
};
