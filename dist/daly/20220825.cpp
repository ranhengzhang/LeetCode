#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int size = arr.size();
        int a, b;
        vector<int>::iterator it = arr.begin();

        while (size > k) {
            a = *it;
            b = *(it + size - 1);
            if ((abs(a - x) > abs(b - x)) || ((abs(a - x) == abs(b - x)) && a > b)) {
                ++it;
            }
            --size;
        }

        return vector<int>(it, it + size);
    }
};
