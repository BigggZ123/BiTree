//
// Created by lenovo on 2023/12/13.
//

#ifndef BITREE_NODEITER_H
#define BITREE_NODEITER_H
#include <queue>

template <typename T>
class NodeIter{
public:
    virtual NodeIter<T>*LChild      ()                  {return nullptr;};
    virtual NodeIter<T>*RChild      ()                  {return nullptr;};
    virtual NodeIter<T>*parent      ()                  {return nullptr;}
    virtual T           data        ()  = 0 ;
    virtual int         height      ()  = 0 ;
    //有些迭代器不能修改，直接返回reject，及false
    virtual bool        setRChild   (NodeIter<T>* iter) {return false ; }
    virtual bool        setLChild   (NodeIter<T>* iter) {return false; }
    virtual bool        setRChild   (T data)            {return false ;}
    virtual bool        setLChild   (T data)            {return false ;}
};


template <typename T>
bool PreOrder(NodeIter<T>* node , bool(*visit)(NodeIter<T>*)){
    //对空也应当执行访问操作
    if (not node){
        if (not visit(node))
            return false ;
        return true ;
    }

    if (not visit(node))
        return false ;
    if (not PreOrder(node->LChild() , visit))
        return false ;
    if (not PreOrder(node->RChild() , visit))
        return false ;
    return true ;
}

template <typename T>
bool InOrder(NodeIter<T>* node , bool(*visit)(NodeIter<T>*)){
    if (not node){
        if (not visit(node))
            return false ;
        return true ;
    }

    if (not InOrder(node->LChild() , visit))
        return false ;
    if (not visit(node))
        return false ;
    if (not InOrder(node->RChild() , visit))
        return false ;
    return true ;
}

template <typename T>
bool PostOrder(NodeIter<T>* node , bool(*visit)(NodeIter<T>*)) {
    if (not node) {
        if (not visit(node))
            return false;
        return true;
    }

    if (not PostOrder(node->LChild(), visit))
        return false;
    if (not PostOrder(node->RChild(), visit))
        return false;
    if (not visit(node))
        return false;
    return true;
}

template <typename T>
bool LevelOrder(NodeIter<T>* node , bool (*visit)(NodeIter<T>*)){
    if (not node)
        return true ;

    std::queue<NodeIter<T>*> nodes ;
    nodes.push(node);
    while (not nodes.empty()){
        NodeIter<T>* cur = nodes.front();
        nodes.pop();

        if (not visit(cur))
            return false ;
        //因为有时会对NULL也执行访问操作
        //故nullptr有必要入队列
        if (cur != nullptr){
            nodes.push(cur->LChild());
            nodes.push(cur->RChild());
        }

    }
}

template <typename T>
int Height(NodeIter<T>* root){
    if (not root) return -1 ;
    if (not root->LChild() and not root->RChild()) return 0 ;

    return std::max(
            Height(root->LChild()),
            Height(root->RChild())
            )
            + 1 ;
}

template <typename T>
int Depth(NodeIter<T>* root , NodeIter<T>* node){
    if (root == nullptr or node == nullptr) return -1 ;
    if (root == node) return 0 ;

    int leftDepth = Depth(root->LChild() , node);
    if (leftDepth != -1) return leftDepth + 1 ;

    int rightDepth = Depth(root->RChild() , node) ;
    if (rightDepth != -1) return rightDepth + 1 ;

    return -1 ;
}

#endif //BITREE_NODEITER_H
