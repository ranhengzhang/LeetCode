#include <bits/stdc++.h>

using std::greater;
using std::iter_swap;
using std::string;
using std::to_string;

class Solution
{
public:
    int maximumSwap(int num)
    {
        string before = to_string(num), after = to_string(num);
        int size = before.size();
        int n = 0;

        sort(after.begin(), after.end(), greater<char>());
        while (before[n] == after[n] && n < size)
            ++n;
        if (n == size)
            return num;
        iter_swap(before.begin() + n, before.begin() + before.find_last_of(after[n]));

        return stoi(before);
    }
};

int main(int argc, char const *argv[])
{
    Solution S;
    S.maximumSwap(98368);
    return 0;
}
