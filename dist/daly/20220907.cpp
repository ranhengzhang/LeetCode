#include <bits/stdc++.h>

using std::pair;
using std::string;
using std::swap_ranges;
using std::vector;

class Solution
{
public:
    string reorderSpaces(string text)
    {
        int size = text.size();
        int zeroCount = 0;
        vector<pair<int, int>> wordBegin;

        for (int i = 0; i < size; ++i)
        {
            if (text[i] == ' ')
            {
                ++zeroCount;
            }
            else
            {
                wordBegin.emplace_back(i, i);
                while (islower(text[i]))
                {
                    ++i;
                }
                (*wordBegin.rbegin()).second = i;
                --i;
            }
        }
        if (wordBegin.size() == 1)
            swap_ranges(text.begin() + wordBegin[0].first, text.begin() + wordBegin[0].second, text.begin());
        else
        {
            string space(zeroCount / (wordBegin.size() - 1), ' ');

            text.replace(text.begin() + (*wordBegin.rbegin()).second, text.end(), string(zeroCount % (wordBegin.size() - 1), ' '));
            for (int i = wordBegin.size() - 1; i > 0; --i)
            {
                text.replace(text.begin() + wordBegin[i - 1].second, text.begin() + wordBegin[i].first, space);
            }
            text.replace(text.begin(), text.begin() + wordBegin[0].first, "");
        }

        return text;
    }
};
