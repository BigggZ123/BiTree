//
// Created by lenovo on 2023/12/13.
//

#ifndef BITREE_BITREENODE_H
#define BITREE_BITREENODE_H

#include "Node_Template.h"
//仿照nodeTemplate来定义一个符合模版的BiTreeNode
template <typename T>
class BiTreeNode{
public:
    BiTreeNode(T data) : _data(data) {
        this->_l_child = nullptr;
        this->_r_child = nullptr;
    }
    T&                  data()      {return this->_data;}
    BiTreeNode<T>*&     LChild()    {return this->_l_child;}
    BiTreeNode<T>*&     RChild()    {return this->_r_child;}
protected:
    T _data ;
    BiTreeNode<T>* _l_child ;
    BiTreeNode<T>* _r_child ;
};


#endif //BITREE_BITREENODE_H
