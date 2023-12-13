//
// Created by lenovo on 2023/12/13.
//

#ifndef BITREE_INODE_H
#define BITREE_INODE_H
//对BiTreeNode的抽象，后续方便使用template来类似iter的行为
template <typename T>
class iNode{
public :
    T data ;
    iNode<T>*&  LChild() ;
    iNode<T>*&  RChild() ;
    iNode(T data) : data(data) {
        this->_l_child = nullptr ;
        this->_r_child = nullptr ;
    };
protected:
    iNode<T>* _r_child ;
    iNode<T>* _l_child ;
};

template<typename T>
iNode<T> *&iNode<T>::RChild() {
    return this->_r_child;
}

template<typename T>
iNode<T> *&iNode<T>::LChild() {
    return this->_l_child ;
}

#endif //BITREE_INODE_H
