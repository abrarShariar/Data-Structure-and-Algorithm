/*
    tree traversal
    - PRE ORDER
    - POST ORDER
    - IN ORDER
*/
#include<iostream>
#include "CompleteTree.h"
using namespace std;


int main(){

    CompleteBinaryTree<char>tree(5);
    tree.insertNode('A');
    tree.insertNode('B');
    tree.insertNode('C');
    tree.insertNode('D');
    tree.insertNode('E');

    cout<<"Pre-Order Traversal: "<<endl;
    tree.preOrder(0);
    cout<<"In-Order Traversal: "<<endl;
    tree.inOrder(0);
    cout<<"Post-Order Traversal: "<<endl;
    tree.postOrder(0);

}
