/*
    BUGGY CODE
    PROBLEM IN insertNode()

    FIX OUTPUT (garbage value)
    implementing BST using template
*/
#include<iostream>
using namespace std;

template<typename Type>class BinarySearchTree{
    private:
        int treeSize;
        int maxSize;
                 //pointer to an array
    public:
        Type *tree;
        BinarySearchTree(int treeSize){
            this->maxSize=0;
            this->treeSize=treeSize;
            Type *tree=new Type[treeSize];
            this->tree=tree;
            //initialize
        }
        void insertNode(Type,int);
        Type getNode(int);
        int getTreeSize();
};
template<typename Type>int BinarySearchTree<Type>::getTreeSize(){
    return this->maxSize;
}

template<typename Type>void BinarySearchTree<Type>::insertNode(Type item,int root){
    //initial condition
    if(this->maxSize==0){
        this->tree[root]=item;
        this->maxSize=root+1;
    }

    //ERROR HANDLING
    if(this->maxSize>=this->treeSize){
        //dynamically allocate array
        Type newTree[(2*this->treeSize)];
        for(int i=0;i<this->treeSize;i++){
            newTree[i]=this->tree[i];
        }
        //delete this->tree;
        this->tree=newTree;
        this->treeSize=2*this->treeSize;
    }

    if(this->tree[root]==NULL){
        this->tree[root]=item;
        if(root>=this->maxSize){
            this->maxSize=root;
        }
        return;
    }


    //move to left subtree
    else if(item < this->tree[root]){
        root=2*root+1;
        this->insertNode(item,root);
    }
    //move to right subtree
    else if(item > this->tree[root]){
        root=2*root+2;
        this->insertNode(item,root);
    }
}

template<typename Type>Type BinarySearchTree<Type>::getNode(int position){
    return this->tree[position];
}

int main(){

    BinarySearchTree<int> Tree(5);
    for(int i=0;i<5;i++){
        int item;
        cout<<"Insert Item: ";
        cin>>item;
        Tree.insertNode(item,0);
    }

    cout<<Tree.getTreeSize()<<endl;
    /*
        test print
        ERROR: NULL value for empty nodes
    */


    for(int i=0;i<;i++){
        cout<<Tree.tree[i]<<endl;
    }

/*
    BinarySearchTree<int>BST;
    int arr[]={10,20,304,50};
    BST.tree=arr;
    cout<<BST.tree[0]<<endl;
*/
}
