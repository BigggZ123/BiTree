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
class CompleteTree<T>::iterator : protected NodeIter<T>{
public :
    explicit iterator(int idx , std::vector<T>& dats) : datas(dats) , idx(idx){}
    iterator() = default;
    static int treeHeight(std::vector<T> tree){
        int height = -1 ;
        int _h = 1 ;
        int _len = tree.size() ;
        while (_len >= _h){
            height ++ ;
            _h *= 2 ;
//            cout << height << endl ;
        }
        return height;
    }

    int height() override{
        if (datas.size() == 0)
            return -1 ;
        std::vector<T> now (idx + 1);
        return treeHeight(datas) - treeHeight(now) ;
    }

    T data() override{
        return datas[idx];
    }

protected:
    std::vector<T>& datas ;
    int idx     {-1} ;
};

#endif //BITREE_COMPLETETREE_H
