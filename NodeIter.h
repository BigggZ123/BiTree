//
// Created by lenovo on 2023/12/13.
//

#ifndef BITREE_NODEITER_H
#define BITREE_NODEITER_H

template <typename T>
class NodeIter{
public:
    virtual NodeIter<T>* LChild()    = 0 ;
    virtual NodeIter<T>* RChild()    = 0 ;
    virtual T           data()      = 0 ;
    virtual int         height()    = 0 ;
};

template <typename T>
class iBiTree{
public :
    virtual NodeIter<T>* root() = 0 ;
    static bool PreOrder(NodeIter<T>* node , bool(*visit)(NodeIter<T>*)){
        if (not visit(node))
            return false ;
        if (not visit(node->LChild()))
            return false ;
        if (not visit(node->RChild()))
            return false ;
        return true ;
    }
    virtual bool preOrder(bool (*visit)(NodeIter<T>*)){
        return PreOrder(this->root() , visit);
    }
};
#endif //BITREE_NODEITER_H
