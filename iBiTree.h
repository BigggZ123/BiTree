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
    virtual NodeIter<T>* root() { return nullptr;}

    static bool PreOrder(NodeIter<T>* node , bool(*visit)(NodeIter<T>*)){
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

    virtual bool preOrder(bool (*visit)(NodeIter<T>*)){
        return PreOrder(this->root() , visit);
    }

    static bool InOrder(NodeIter<T>* node , bool(*visit)(NodeIter<T>*)){
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

    virtual bool inOrder(bool (*visit)(NodeIter<T>*)){
        return InOrder(this->root() , visit);
    }

    static bool PostOrder(NodeIter<T>* node , bool(*visit)(NodeIter<T>*)) {
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

    virtual bool postOrder(bool (*visit)(NodeIter<T>*)){
        return PostOrder(this->root() , visit);
    }

    static bool LevelOrder(NodeIter<T>* node , bool (*visit)(NodeIter<T>*)){
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
        return true ;
    }

    virtual  bool levelOrder(bool (*visit)(NodeIter<T>*)){
        return LevelOrder(this->root() , visit);
    }
};
#endif //BITREE_IBITREE_H
