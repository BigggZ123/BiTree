//
// Created by lenovo on 2023/12/13.
//

#ifndef BITREE_BINARYSEARCHTREE_H
#define BITREE_BINARYSEARCHTREE_H
#include "BiTree.h"
#include "BiTreeContainer.h"
template <typename T>
class BinarySearchTree : public BiTree<T> , BiTreeContainer<T>{
public :
    using iterator = typename BiTree<T>::iterator;
    using BiTree<T>::levelOrder ;
    using BiTree<T>::preOrder ;
    using BiTree<T>::inOrder ;
    using BiTree<T>::postOrder;
    BinarySearchTree(bool (*comp) (T , T)) : BiTree<T>(nullptr) {}
public:
    bool        insert  (T data) override ;
    bool        remove  (T data) override ;
    NodeIter<T>*locate  (T data) override ;
    static BiTreeNode<T>* Digout(BiTree<T>* node);
protected:
    bool (* comp)(T, T) ;
};

#endif //BITREE_BINARYSEARCHTREE_H
