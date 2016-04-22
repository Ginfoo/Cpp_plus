#pragma once//二叉树
#include<iostream>
#include"SeqStack.h"
#include <cstdlib>
template<class T>
struct BinTreeNode {
    T data;
    BinTreeNode<T>* leftChild, *rightChild;
    BinTreeNode() : leftChild(NULL), rightChild(NULL) {}
    BinTreeNode(T x, BinTreeNode<T>* l = NULL, BinTreeNode<T>* r = NULL)
        : data(x), leftChild(l), rightChild(r) {};
};
template<class T>
class BinaryTree {
public:
    BinaryTree() : root(NULL) {}
    BinaryTree(T value) : RefValue(value), root(NULL) {}
    BinaryTree(BinaryTree<T>& s);
    ~BinaryTree() {
        destory(root);
    }
    bool IsEmpty() {
        return (root == NULL) ? true : false;
    }
    BinTreeNode<T>* Parent(BinTreeNode<T>* curr) {
        return (root == NULL || root == curr) ? NULL : Parent(root, current);
    }
    BinTreeNode<T>* LeftChild(BinTreeNode<T>* curr) {
        return (curr != NULL) ? curr->leftChild : NULL;
    }
    BinTreeNode<T>* RightChild(BinTreeNode<T>* curr) {
        return (curr != NULL) ? curr->rightChild : NULL;
    }
    int Height() {
        return Height(root);
    }
    int Size() {
        return Size(root);
    }
    BinTreeNode<T>* getRoot()const {
        return root;
    }
    void preOrder(void(*visit)(BinTreeNode<T>* p)) {
        preOrder(root, visit);
    }
    void inOrder(void(*visit)(BinTreeNode<T>* p)) {
        inOrder(root, visit);
    }
    void postOrder(void(*visit)(BinTreeNode<T>* P)) {
        postOrder(root, visit);
    }
    void levelOrder(void(*visit)(BinTreeNode<T>* p));
    int Inset(const T& item);
    BinTreeNode<T>* Find(T& item)const;
protected:
    BinTreeNode<T>* root;
    T RefValue;
    void CreateBinTree(istream& in, BinTreeNode<T>*& subTree);
    bool Insert(BinTreeNode<T>*& subTree, const T& x);
    void destory(BinTreeNode<T>*& subTree);
    bool Find(BinTreeNode<T>* subTree, const T& x)const;
    BinTreeNode<T>* Copy(BinTreeNode<T>* orig);
    int Height(BinTreeNode<T>* subTree);
    int Size(BinTreeNode<T>* subTree);
    BinTreeNode<T>* Parent(BinTreeNode<T>* subTree, BinTreeNode<T>* curr);
    BinTreeNode<T>* Find(BinTreeNode<T>* subTree, const T& x);
    void Traverse(BinTreeNode<T>* subTree, ostream& out);
    void preOrder(BinTreeNode<T>& subTree, void(*visit)(BinTreeNode<T>* p));
    void inOrder(BinTreeNode<T>& subTree, void(*visit)(BinTreeNode<T>* p));
    void postOrder(BinTreeNode<T>& subTree, void(*visit)(BinTreeNode<T>* p));
    friend istream& operator>>(istream& in, BinaryTree<T>& Tree);
    friend ostream& operator<<(ostream& out, BinaryTree<T>& Tree);
    friend int operator(const BinaryTree<T>& s, const BinaryTree<T>& t);
};

template<class T>
void BinaryTree<T>::destory(BinTreeNode<T>* subTree) {
    if (subTree != NULL) {
        destory(subTree->leftChild);
        destory(subTree->rightChild);
        delete subTree;
    }
};
template<class T>
BinTreeNode<T>* BinaryTree<T>::Parent(BinTreeNode<T>* subTree, BinTreeNode<T>* curr) {
    if (subTree == NULL)return NULL;
    if (subTree->leftChild == curr || subTree->rightChild == curr) return subTree;
    BinTreeNode<T>* p;
    if ((p = Parent(subTree->leftChild, curr)) != NULL) return p;
    else return Parent(subTree->rightChild, curr);
};
template<class T>
void BinaryTree<T>::Traverse(BinTreeNode<T>* subTree, ostream& out) {
    if (subTree != NULL) {
        out << subTree->data << ' ';
        Traverse(subTree->leftChild, out);
        Traverse(subTree->rightChild, out);
    }
};
template<class T>
istream& operator>>(istream& in, BinaryTree<T>& Tree) {
    CreateBinTree(in, Tree.root);
    return in;
};
template<class T>
ostream& operator<<(ostream& out, BinaryTree<T>& Tree) {
    out << "二叉树的前序遍历\n";
    Tree.Traverse(Tree.root, out);
    out << endl;
    return out;
};
template<class T>
void BinaryTree<T>::CreateBinTree(istream& in, BinTreeNode<char>*& BT) {
    SeqStack<BinTreeNode<char>*> s;
    BT = NULL;
    BinTreeNode<char>* p, *t;
    int k;
    char ch;
    in >> ch;
    while (ch != RefValue) {
        switch (ch) {
            case'(':
                s.Push(p);
                k = 1;
                break;
            case')':
                s.Pop(t);
                break;
            case','k = 2;
                break;
            default:
                p = new BinTreeNode<char>(ch);
                if (BT == NULL) BT = p;
                else if (k = 1) {
                    s.getTop(t);
                    t->leftChild = p;
                } else {
                    s.getTop(t);
                    t->rightChild = p;
                }
        }
        in >> ch;
    }
};
template<class T>
void BinaryTree<T>::inOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T>* p)) {
    if (subTree != NULL) {
        inOrder(subTree->leftChild, visit);
        visit(subTree);
        inOrder(subTree->rightChild, visit);
    }
}
template<class T>
void BinaryTree<T>::preOrder(BinTreeNode<T>& subTree, void(*visit)(BinTreeNode<T>* p)) {
    if (subTree != NULL) {
        visit(subTree);
        preOrder(subTree->leftChild, visit);
        preOrder(subTree->rightChild, visit);
    }
}
template<class T>
void BinaryTree<T>::postOrder(BinTreeNode<T>& subTree, void(*visit)(BinTreeNode<T>* p)) {
    if (subTree != NULL) {
        postOrder(subTree->leftChild, visit);
        postOrder(subTree->rightChild, visit);
        visit(subTree);
    }
}
template<class T>
int BinaryTree<T>::Size(BinTreeNode<T>* subTree)const {
    if (subTree == NULL) return 0;
    else return 1 + Size(subTree->leftChild) + Size(subTree->rightChild);
}
template<class T>
int BinaryTree<T>::Height(BinTreeNode<T>* subTree) {
    if (subTree == NULL) return 0;
    else {
        int i = Height(subTree->leftChild);
        int j = Height(subTree->rightChild);
        return (i < j) ? j + 1 : i + 1;
    }
}
template<class T>
BinaryTree<T>::BinaryTree(BinaryTree<T>& s) {
    root = Copy(s.root);
}
template<class T>
BinTreeNode<T>* BinaryTree<T>::Copy(BinTreeNode<T>* orig) {
    if (orig == NULL) return NULL;
    BinTreeNode<T>* temp = new BinTreeNode<T>;
    temp->data = orig->data;
    temp->leftChild = Copy(orig->leftChild);
    temp->rightChild = Copy(orig->rightChild);
    return temp;
}
template<class T>
int operator==(const BinaryTree<T>& s, const BinaryTree<T>& t) {
    return (equal(s.root, t.root)) ? true : false;
}
template<class T>
bool equal(BinTreeNode<T>* a, BinTreeNode<T>* b) {
    if (a == NULL && b == NULL)return true;
    if (a != NULL && b != NULL && a->data == b->data
            && equal(a->leftChild, b->leftChild)
            && equal(a->rightChild, b->rightChild))return true;
    else return false;
}