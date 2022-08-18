#include <bits/stdc++.h>

class MyCircularDeque
{
private:
    int size = 0;
    int *arr = nullptr;
    int front = 1;
    int bottom = 0;
    int mod(const int __base, const int __mod)
    {
        auto temp = __base % __mod;
        return temp + (temp < 0 ? __mod : 0);
    }

public:
    MyCircularDeque(int k)
    {
        this->size = k;
        this->arr = new int[k];
    }

    bool insertFront(int value)
    {
        if (this->isFull())
            return false;
        else
        {
            this->arr[this->mod(this->front++, this->size)] = value;
            return true;
        }
    }

    bool insertLast(int value)
    {
        if (this->isFull())
            return false;
        else
        {
            this->arr[this->mod(this->bottom--, this->size)] = value;
            return true;
        }
    }

    bool deleteFront()
    {
        if (this->isEmpty())
            return false;
        else
        {
            --this->front;
            return true;
        }
    }

    bool deleteLast()
    {
        if (this->isEmpty())
            return false;
        else
        {
            ++this->bottom;
            return true;
        }
    }

    int getFront()
    {
        return this->isEmpty() ? -1 : this->arr[this->mod(this->front - 1, this->size)];
    }

    int getRear()
    {
        return this->isEmpty() ? -1 : this->arr[this->mod(this->bottom + 1, this->size)];
    }

    bool isEmpty()
    {
        return this->front - this->bottom - 1 == 0;
    }

    bool isFull()
    {
        return this->front - this->bottom - 1 == this->size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main(int argc, char const *argv[])
{
    MyCircularDeque circularDeque = *new MyCircularDeque(3); // 设置容量大小为3
    circularDeque.insertLast(1);                             // 返回 true
    circularDeque.insertLast(2);                             // 返回 true
    circularDeque.insertFront(3);                            // 返回 true
    circularDeque.insertFront(4);                            // 已经满了，返回 false
    circularDeque.getRear();                                 // 返回 2
    circularDeque.isFull();                                  // 返回 true
    circularDeque.deleteLast();                              // 返回 true
    circularDeque.insertFront(4);                            // 返回 true
    circularDeque.getFront();                                // 返回 4
    return 0;
}
