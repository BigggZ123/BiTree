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

int main() {
    vector<int> v ;
    for (int i = 0 ; i < 7 ;  i ++){
        v.push_back(i + 1);
    }
    CompleteTree<int> ct ;
    for (int i =  0 ; i < 100 ; i ++){
        ct.insert(i + 1) ;
    }
    auto it = ct.root() ;
//    cout << ct.root()->LChild()->LChild()->parent()->parent()->data() << endl ;
    ct.preOrder(visit);
//    BinarySearchTree<int> bst ;
}
