#include <bits/stdc++.h>
using namespace std;
class OrderedStream
{
private:
    vector<string> stream;
    int ptr = 0;
    void next()
    {
        ++this->ptr;
        if (this->ptr == this->stream.size() || this->stream[this->ptr].empty())
            return;
        this->next();
    }

public:
    OrderedStream(int n)
    {
        this->stream.resize(n);
    }

    vector<string> insert(int idKey, string value)
    {
        int start = this->ptr, end = this->ptr;
        this->stream[idKey - 1] = value;
        if (idKey - 1 == this->ptr)
        {
            this->next();
            end = this->ptr;
        }

        return vector<string>(this->stream.begin() + start, this->stream.begin() + end);
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
