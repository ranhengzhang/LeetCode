#include <bits/stdc++.h>

using std::vector;
using std::sort;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        return target == arr;
    }
};

int main(int argc, char const *argv[])
{
    Solution S;
    vector<int> V1({1,2,3,4}), V2({2,4,1,3});
    std::cout << (S.canBeEqual(V1, V2) ? "true" : "false");
    return 0;
}
