#include <bits/stdc++.h>

using std::string;
using std::count;
using std::next;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        size_t index = sentence.find(searchWord);
        if (index == -1) return index;
        else {
            if (index == 0) return 1;
            else {
                index = sentence.find(searchWord.insert(0, " "));
                if (index == -1) return index;
                else return count(sentence.begin(), next(sentence.begin(), index), ' ') + 1;
            }
        }
    }
};
