#include <iostream>
#include "Node_Template.h"
#include "BiTreeNode.h"
#include <vector>
using namespace std ;

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<BiTreeNode<int>*> nodes ;
    nodes.reserve(10);
    for (int i = 0 ; i < 10 ; i ++){
        nodes.push_back(new BiTreeNode<int>(i));
    }
    nodes[0]->LChild() = nodes[1];
    cout << nodes[0]->LChild()->data() << endl ;
    return 0;
}
