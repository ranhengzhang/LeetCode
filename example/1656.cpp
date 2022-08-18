#include <bits/stdc++.h>

using std::string;
using std::vector;

class OrderedStream
{
public:
    int _size, ptr;
    vector<string> stream;
    OrderedStream(int n) : _size(n), ptr(1)
    {
        stream.assign(n, "");
    }

    vector<string> insert(int idKey, string value)
    {
        stream[idKey - 1] = value;
        vector<string> ans;
        while (ptr <= _size && stream[ptr - 1] != "")
        {
            ans.push_back(stream[ptr - 1]);
            ptr++;
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
