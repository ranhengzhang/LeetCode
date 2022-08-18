#include <bits/stdc++.h>

using std::vector;

class MyCircularDeque
{
public:
    MyCircularDeque(int k) : CDeque(vector<int>(k + 1, 0)) {}

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        front = getIndex(front - 1);
        CDeque[front] = value;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        CDeque[rear] = value;
        rear = getIndex(rear + 1);
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        front = getIndex(front + 1);
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        rear = getIndex(rear - 1);
        return true;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return CDeque[front];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return CDeque[getIndex(rear - 1)];
    }

    bool isEmpty()
    {
        return front == rear;
    }

    bool isFull()
    {
        return getIndex(rear + 1) == front;
    }

private:
    vector<int> CDeque;
    int front = 0, rear = 0; // front: 第一个有效数据的位置; rear: 最后一个有效数据的下一个位置

    inline int getIndex(int index)
    {
        // 两个关键转换：CDeque.size() -> 0, -1 -> CDeque.size() - 1
        return (index + CDeque.size()) % (CDeque.size());
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
