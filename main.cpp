#include <iostream>
#include "NodeIter.h"
#include "BiTree.h"
#include <vector>
#include "BinarySearchTree.h"
using namespace std ;


int main() {
//    vector<BiTreeNode<int>*> nodes ;
//    for (int i = 0 ; i < 10 ; i ++){
//        nodes.push_back(new BiTreeNode<int>(i));
//    }
//    BiTree<int> bt(nodes[0]);
//    bt.root()->setLChild(10);
//    bt.root()->setRChild(20);
//    bt.root()->LChild()->setLChild(30);
//    bt.root()->LChild()->LChild()->setLChild(40);
////    auto it = (BiTree<int>::iterator*)bt.root() ;
////    cout << it->base()->LChild->LChild->data << endl ;
////    NodeIter<int>* it = bt.root()->LChild()->LChild() ;
////    cout << it->data() << endl ;
//    bt.preOrder([](NodeIter<int> * iter)->bool {
//        if (not iter)
//            return true ;
//        else
//            cout <<  iter->data() << ":\t" <<iter->height() << endl ;
//        return true ;
//    });

}
