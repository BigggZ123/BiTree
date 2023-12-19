//
// Created by lenovo on 2023/12/13.
//

#ifndef BITREE_COMPLETETREE_H
#define BITREE_COMPLETETREE_H
#include "iBiTree.h"
#include <vector>
#include "BiTreeContainer.h"
#include <algorithm>

template <typename T>
class CompleteTree : public  BiTreeContainer<T> {
public :
    class iterator ;
public :
    NodeIter<T>*    root    () override ;
    bool            insert  (T data) override ;
    bool            remove  (T data) override ;
    NodeIter<T>*    locate  (T data) override ;
protected:
public:
    std::vector<T> datas ;
};


template<typename T>
bool CompleteTree<T>::remove(T data) {
    auto tat = find(this->datas.begin() , this->datas.end() , data);
    if (tat == this->datas.end()){
        return false ;
    }
    this->datas.erase(tat);
    return true ;
}

template<typename T>
bool CompleteTree<T>::insert(T data) {
    this->datas.push_back(data);
    return true ;
}

template<typename T>
NodeIter<T> *CompleteTree<T>::locate(T data) {
    for (int i = 0 ; i < this->datas.size() ; i ++){
        if (this->datas[i] == data){
            return new CompleteTree<T>::iterator(i , this->datas);
        }
    }
    return nullptr;
}

template<typename T>
NodeIter<T> *CompleteTree<T>::root() {
    return new CompleteTree<T>::iterator( 0 , this->datas);
}

template<typename T>
class CompleteTree<T>::iterator : public NodeIter<T>{
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

    NodeIter<T>* LChild() override{
        int idx = this->idx * 2 + 1 ;
        if (idx < 0 or idx >= this->datas.size()){
            return nullptr;
        }
        return new CompleteTree<T>::iterator(
                idx ,
                this->datas
                );
    }
    NodeIter<T>* RChild() override{
        int idx = this->idx * 2 + 2 ;
        if (idx < 0 or idx >= this->datas.size()){
            return nullptr;
        }
        return new CompleteTree<T>::iterator(
                idx ,
                this->datas
        );
    }
    NodeIter<T>* parent() override{
        int offset = this->idx % 2 ;
        int idx ;
        if (offset){
            idx = this->idx/2 ;
        }else{
            idx = this->idx/2 - 1 ;
        }
        if (idx < 0 or idx >= this->datas.size()){
            return nullptr;
        }
        return new CompleteTree<T>::iterator(
                idx ,
                this->datas
        );
    }
protected:
    std::vector<T>& datas ;
    int idx     {-1} ;
};

#endif //BITREE_COMPLETETREE_H
