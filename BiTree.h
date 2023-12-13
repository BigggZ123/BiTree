//
// Created by lenovo on 2023/12/13.
//
#include <iostream>
using namespace std ;

#ifndef BITREE_BITREE_H
#define BITREE_BITREE_H
#include "NodeIter.h"
#include "iBiTree.h"
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
//此处何不直接使用iter作为节点，而是单独定义节点而iter作为节点的包装呢？
//还是为了为“访问节点”提供一个中间层
//这样后续的AVL的时候才不会遇到"节点缺少属性"的问题
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
auto Height (BiTreeNode<T> *node){
    if (not node){
        return -1 ;
    }

    int LH = Height(node->LChild);
    int RH = Height(node->RChild);

    if (LH > RH)
        return LH + 1 ;
    else
        return RH + 1 ;

}

template <typename T>
class BiTree<T>::iterator : public NodeIter<T>{
public :
    iterator() = default ;
    explicit iterator(BiTreeNode<T>* node) : cur(node) {}
    explicit iterator(T data) : cur(new BiTreeNode<T>(data)){}

    NodeIter<T>* LChild () override{
        if (cur->LChild){
            return new BiTree<T>::iterator(cur->LChild);
        }
//        cout << "Pass a None class" << endl ;
        return nullptr;
    }
    NodeIter<T>* RChild () override {
        if (cur->RChild)
            return new BiTree<T>::iterator(cur->RChild);
//        cout << "Pass a None class" << endl ;
        return nullptr;
    }
    T data() override{
        return cur->data ;
    }
    int height()override{
        return Height(this->cur) ;
    }
    bool setRChild(NodeIter<T>* iter) override{
        if (not iter){
            return false ;
        }
        auto bi_iter = (BiTree<T>::iterator*) iter ;
        this->cur->RChild = bi_iter->base() ;
        return true ;
    }

    bool setLChild(NodeIter<T>* iter) override{
        if (not iter){
            return false ;
        }
        auto bi_iter = (BiTree<T>::iterator*) iter ;
        this->cur->LChild = bi_iter->base() ;

        return true ;
    }

    bool setRChild(T data) override{
        this->cur->RChild = new BiTreeNode<T>(data);
        return true ;
    }

    bool setLChild(T data) override{
        this->cur->LChild = new BiTreeNode<T>(data);
        return true ;
    }

    BiTreeNode<T>* base(){
        return this->cur ;
    }
protected:
    BiTreeNode<T>* cur ;
};

#endif //BITREE_BITREE_H
