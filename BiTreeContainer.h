//
// Created by lenovo on 2023/12/15.
//

#ifndef BITREE_BITREECONTAINER_H
#define BITREE_BITREECONTAINER_H
#include "iBiTree.h"
template <typename T>
class BiTreeContainer : public iBiTree<T>{
    virtual bool    insert (T data) {return false;}
    virtual bool    remove (T data) {return false;}
    virtual NodeIter<T>* locate (T data) {return nullptr;}
};

#endif //BITREE_BITREECONTAINER_H
