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
}
