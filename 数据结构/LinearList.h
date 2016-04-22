#pragma once//线性表的抽象基类
template<class T>
class LinerList {
public:
    LinerList();
    ~LinerList();
    virtual int Size()const = 0;
    virtual int Length()const = 0;
    virtual int Search(T& x)const = 0;
    virtual int Locate(int i)const = 0;
    virtual bool getData(int i, T& x)const = 0;
    virtual void setData(int i, T& x) = 0;
    virtual bool Inset(int i, T& x) = 0;
    virtual bool Remove(int i, T& x) = 0;
    virtual bool IsEmpty()const = 0;
    virtual bool IsFull()const = 0;
    virtual void Sort() = 0;
    virtual void input() = 0;
    virtual void output() = 0;
    virtual LinerList<T> operator=(LinerList<T>& L) = 0;
};