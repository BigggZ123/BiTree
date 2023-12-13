#include <iostream>
#include "iNode.h"
#include <vector>
using namespace std ;

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<iNode<int>*> nodes ;
    for (int i = 0 ; i < 10 ; i ++){
        nodes.push_back(new iNode<int>(i));
    }
    nodes[0]->LChild() = nodes[1];
    cout << nodes[0]->LChild()->data << endl ;
    return 0;
}
