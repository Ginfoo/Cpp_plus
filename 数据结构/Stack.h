#pragma once//栈的抽象数据类型
const int maxSize = 50;
template<class T>
class Stack {
public:
    Stack() {};
    virtual void Push(const T& x) = 0;
    virtual bool Pop(T& X) = 0;
    virtual bool getTop(T& x)const = 0;
    virtual bool IsEmpty()const = 0;
    virtual bool IsFull()const = 0;
    virtual int getSize()const = 0;
};
