//
// Created by lenovo on 2023/12/13.
//

#ifndef BITREE_IBITREE_H
#define BITREE_IBITREE_H
#include "NodeIter.h"
#include <queue>
template <typename T>
class iBiTree{
public :
    virtual NodeIter<T>* root() = 0 ;


    virtual bool preOrder(bool (*visit)(NodeIter<T>*)){
        return PreOrder(this->root() , visit);
    }


    virtual bool inOrder(bool (*visit)(NodeIter<T>*)){
        return InOrder(this->root() , visit);
    }

    virtual bool postOrder(bool (*visit)(NodeIter<T>*)){
        return PostOrder(this->root() , visit);
    }

    virtual  bool levelOrder(bool (*visit)(NodeIter<T>*)){
        return LevelOrder(this->root() , visit);
    }
};

#endif //BITREE_IBITREE_H
