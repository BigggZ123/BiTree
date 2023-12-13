//
// Created by lenovo on 2023/12/13.
//

#ifndef BITREE_NODEITER_H
#define BITREE_NODEITER_H

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


#endif //BITREE_NODEITER_H
