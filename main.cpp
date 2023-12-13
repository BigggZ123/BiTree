#include <iostream>
#include "NodeIter.h"
#include "BiTree.h"
#include <vector>
using namespace std ;


int main() {
    vector<BiTreeNode<int>*> nodes ;
    for (int i = 0 ; i < 10 ; i ++){
        nodes.push_back(new BiTreeNode<int>(i));
    }
    BiTree<int> bt(nodes[0]);
    bt.preOrder([](NodeIter<int> * iter)->bool {if (iter)cout << iter->data() << endl ;else cout << "None" << endl ; return true ;});
}
