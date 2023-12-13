#include <iostream>
#include "NodeIter.h"
#include "BiTree.h"
#include <vector>
#include "BinarySearchTree.h"
#include "CompleteTree.h"
using namespace std ;


int main() {
//    const int size = 8 ;
//    vector<vector<int> > vecs(size);
//    for(int i = 0 ; i < size ; i ++){
//        for (int j = 0 ; j < i ; j ++){
//            vecs[i].push_back(1);
//        }
//    }
//    cout << "Loaded!" << endl ;
//    for (auto it = vecs.begin(); it != vecs.end() ; it ++){
//        cout << CompleteTree<int>::iterator::treeHeight(*it) << endl ;
//    }
//    cout << vecs.size() << endl ;
//    vector<int> v(10);
//    v.push_back(100);
//    cout << v.size() << endl ;
    vector<int> v(7);
    for (int i = 0 ; i < 7 ; i ++){
        CompleteTree<int>::iterator it (i, v);
        cout << it.height() << endl ;

    }


}
