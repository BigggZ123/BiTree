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

    NodeIter<T>* root() override{
        return new iterator(this->_root);
    }

protected:
    BiTreeNode<T>* _root ;
};

template <typename T>
class BiTree<T>::iterator : public NodeIter<T>{
public :
    explicit iterator(BiTreeNode<T>* node) : cur(node) {}
    NodeIter<T>* LChild () override{
        if (cur->LChild){
            return new BiTree<T>::iterator(cur->LChild);
        }
        return nullptr;
    }
    NodeIter<T>* RChild () override {
        if (cur->RChild)
            return new BiTree<T>::iterator(cur->RChild);
        return nullptr;
    }
    T data() override{
        return cur->data ;
    }
    int height()override{
        return -2 ;
    }

protected:
    BiTreeNode<T>* cur ;
};

#endif //BITREE_BITREE_H
