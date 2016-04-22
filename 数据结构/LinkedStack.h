#pragma once
//链式栈
#include <iostream>
#include "LinkedList.h"
#include "Stack.h"

template<class T>
class LinkedStack : public Stack<T> {
public:
    LinkedStack(): top(NULL) {}
    ~LinkedStack() {
        makeEmpty();
    }
    void Push(const T& x);
    void Pop(T& x);
    bool getTop(T& x)const;
    bool IsEmpty()const {
        return (top == -1) ? true : false;
    }
    int getSize()const;
    void makeEmpty();
    friend ostream& operator<<(ostream& os, const SeqStack<T>& s);
private:
    LinkNode<T>* top;
};

template<class T>
LinkedStack<T>::makeEmpty() {
    LinkNode<T>* p;
    while (top != NULL) {
        p = top;
        top = top->link;
        delete p;
    }
};
template<class T>
void SeqStack<T>::Push(const T& x) {
    top = new LinkNode<T>(x, top);
    assert(top != NULL);
};
template<class T>
bool LinkedStack<T>::Pop(T& x) {
    if (IsEmpty() == true) return false;
    LinkNode<T>* p = top;
    top = top->link;
    x = p->data;
    delete p;
    return true;
};
template<class T>
bool LinkedStack<T>::getTop(T& x)const {
    if (IsEmpty() == true)return false;
    x = top->data;
    return true;
};
template<class T>
int LinkedStack<T>::getSize()const {
    LinkNode<T>* p = top;
    int k = 0;
    while (p != NULL) {
        p = p->link;
        k++;
    }
    return k;
};
template<class T>
ostream& operator<<(ostream& os, LinkedStack<T>& s) {
    os << "栈中元素个数=" << s.getSize() << endl;
    LinkNode<T>* p = s.top;
    int i = 0;
    while (p! + NULL) {
        os << ++i << ":" << p->data << endl;
        p = p->link;
    }
}