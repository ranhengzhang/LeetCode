#include <bits/stdc++.h>

using std::vector;
using std::stack;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int>::iterator push = pushed.begin(), pop = popped.begin();
        vector<int>::iterator endPush = pushed.end(), endPop = popped.end();
        stack<int> S;

        while (push != endPush || pop != endPop) {
            if (push == endPush) {
                if (!S.empty() && S.top() == *pop) {
                    S.pop();
                    ++pop;
                } else {
                    return false;
                }
            } else {
                if (!S.empty() && S.top() == *pop) {
                    S.pop();
                    ++pop;
                } else {
                    S.push(*push++);
                }
            }
        }

        return true;
    }
};
