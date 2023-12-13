//
// Created by lenovo on 2023/12/13.
//

#ifndef BITREE_NODE_TEMPLATE_H
#define BITREE_NODE_TEMPLATE_H
//对BiTreeNode的抽象，后续方便使用template来类似iter的行为
//预定义一个“Node范式”,之后的node都在此基础上生成
//见BiTreeNode
template <typename T>
class Node_Template{
public :
    virtual T&                  data()   = 0 ;
    virtual Node_Template<T>*&  LChild() = 0 ;
    virtual Node_Template<T>*&  RChild() = 0 ;
};


template <
        typename T  ,
        template <typename>
            typename Node
        >
class iTree{
public :

};

#endif //BITREE_NODE_TEMPLATE_H
