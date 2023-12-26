#include <iostream>
#include "NodeIter.h"
#include "BiTree.h"
#include <vector>
#include "BinarySearchTree.h"
#include "CompleteTree.h"
using namespace std ;

template <typename T>
auto visit (NodeIter<T>* node) -> bool{
    if (not node){
        return true ;
    }
    cout << node->data() << endl;
    return true ;
};

class Counter{
    int _cnt {0};
public:
    template <typename T>
    bool operator() (NodeIter<T>* node){
        if (node != nullptr){
            cout << node->data() << endl ;
            this->_cnt ++ ;
        }
        return true ;
    }

    int result (){
        return this->_cnt ;
    }
};

template <typename T>
using Node = typename BiTree<T>::iterator ;

int main() {
//    vector<int> v ;
//    for (int i = 0 ; i < 7 ;  i ++){
//        v.push_back(i + 1);
//    }
//    CompleteTree<int> ct ;
//    for (int i =  0 ; i < 100 ; i ++){
//        ct.insert(i + 1) ;
//    }
//    auto it = ct.root() ;
////    cout << ct.root()->LChild()->LChild()->parent()->parent()->data() << endl ;
//    ct.preOrder(visit);
//    PreOrder(ct.root() , visit);
//    PreOrder<int, bool(*)(NodeIter<int>*)>(ct.root(), visit);

//    BinarySearchTree<int> bst ;



//    using BiTreeNode = BiTree<int>::iterator ;
//    vector<BiTreeNode*> nodes ;
//    for (int i = 0 ; i < 8 ; i ++){
//        nodes.push_back(new BiTreeNode(i));
//    }
//
//    nodes[0]->setLChild(nodes[1]);
//    nodes[0]->setRChild(nodes[2]);
//    nodes[1]->setLChild(nodes[3]);
//    nodes[1]->setRChild(nodes[4]);
//    nodes[2]->setLChild(nodes[5]);
//    nodes[2]->setRChild(new BiTreeNode(100));
//    nodes[5]->setLChild(nodes[6]);
//    nodes[5]->setRChild(nodes[7]);
//    PreOrder(nodes[0],visit);


    vector<int> v ;
    for (int i = 0 ; i < 7 ;  i ++){
        v.push_back(i + 1);
    }
    CompleteTree<int> ct ;
    for (int i =  0 ; i < 100 ; i ++){
        ct.insert(i + 1) ;
    }
    auto it = ct.root() ;
    Counter cnt ;
    ct.preOrder(cnt);
    cout << cnt.result() << endl ;
}
