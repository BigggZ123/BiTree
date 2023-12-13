//
// Created by lenovo on 2023/12/13.
//

#ifndef BITREE_BITREE_H
#define BITREE_BITREE_H
#include "NodeIter.h"
template <typename T>
class BiTreeNode{
public :
    BiTreeNode(){
        this->LChild = nullptr;
        this->RChild = nullptr;
    }
    explicit BiTreeNode(T data) : data (data) {
        this->LChild = nullptr;
        this->RChild = nullptr;
    };
    BiTreeNode<T>* LChild ;
    BiTreeNode<T>* RChild ;
    T data ;
};

template <typename T>
class BiTree : public iBiTree<T>{
public:
    class iterator ;
public :
    explicit BiTree(BiTreeNode<T>* node) : _root(node) {}

    NodeIter<T>*& root() override{
        return iterator(this->_root);
    }

protected:
    BiTreeNode<T>* _root ;
};

template <typename T>
class BiTree<T>::iterator : public NodeIter<T>{
protected:
    BiTreeNode<T>* cur ;
public:
    explicit iterator(BiTreeNode<T>* node) : cur(node){};
    NodeIter<T>* &RChild() override{return cur->RChild;}
    NodeIter<T>* &LChild() override{return cur->LChild;}
    int height() override {return -2 ;}
    T& data() override{return cur->data;}
};

#endif //BITREE_BITREE_H
