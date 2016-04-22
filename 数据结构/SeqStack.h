#pragma once//Ë³ÐòÕ»
#include<cassert>
#include<iostream>
#include "Stack.h"
const int stackIncreament = 20;//Õ»Òç³öÊ±À©Õ¹¿Õ¼äµÄÔöÁ¿
template<class T>
class SeqStack : public Stack<T> {
public:
    SeqStack(int sz = 50);
    ~SeqStack() {
        delete[] elements;
    }
    void Push(const T& x);
    bool Pop(T& x);
    bool getTop(T& x)const;
    bool IsEmpty()const {
        return (top == -1) ? true : false;
    }
    bool IsFull()const {
        return (top == maxSize - 1) ? true : false;
    }
    int getSize()const {
        return top + 1;
    }
    void MakeEmpty{
        top = -1;
    }
    friend ostream& operator<<(ostream& os, const SeqStack<T>& s);
private:
    T* elements;
    int top;
    int maxSize;
    void overflowProcess();
};
template<class T>
SeqStack<T>::SeqStack(int sz) : top(-1), maxSize(sz) {
    elements = new T[maxSize];
    assert(elements != NULL);
};
template<class T>
void SeqStack<T>::overflowProcess() {
    T* newArray = new T[maxSize + stackIncreament];
    if (newArray = NULL) {
        cerr << "À©ÈÝ´æ´¢·ÖÅäÊ§°Ü" << endl;
        exit(1);
    }
    for (int i = 0; i <= top; i++) {
        newArray[i] = elements[i];
    }
    maxSize = maxSize + stackIncreament;
    delete[] elements;
    elements = newArray;
};
template<class T>
void SeqStack<T>::Push(const T& x) {
    if (IsFull() == true) {
        overflowProcess();
    }
    elements[++top] = x;
};
template<class T>
bool SeqStack<T>::Pop(T& x) {
    if (IsEmpty() == true) {
        return false;
    }
    x = elements[top--];
    return true;
};
template<class T>
bool SeqStack<T>::getTop(T& x)const {
    if (IsEmpty() == true) {
        return false;
    }
    x = elements[top];
    return true;
};
template<class T>
ostream& operator<<(ostream& os, const SeqStack<T>& s) {
    os << "top=" << s.top << emdl;
    for (int i = 0; i <= s.top; i++) {
        os << i << ":" << s.elements[i] << endl;
    }
    return os;
}