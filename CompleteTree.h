//
// Created by lenovo on 2023/12/13.
//

#ifndef BITREE_COMPLETETREE_H
#define BITREE_COMPLETETREE_H
#include "iBiTree.h"
#include <vector>
template <typename T>
class CompleteTree : public iBiTree<T>{
public :
    class iterator ;
public :
    NodeIter<T>* root() override ;

protected:
    std::vector<T> datas ;
};

template<typename T>
NodeIter<T> *CompleteTree<T>::root() {

}

template<typename T>
class CompleteTree<T>::iterator : public NodeIter<T>{
public :
protected:
    std::vector<T>& datas ;
};

#endif //BITREE_COMPLETETREE_H
