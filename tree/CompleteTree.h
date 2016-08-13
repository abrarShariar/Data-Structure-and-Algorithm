/*
    template class for complete binary tree
*/
#include<iostream>
using namespace std;

template<typename Type>class CompleteBinaryTree{
    private:
        int capacity=0;
        int root=0;
        Type* tree;
    public:
        CompleteBinaryTree(int capacity){
            this->capacity=capacity;
            this->tree=new Type[capacity];
        }
        //insert a new item
        void insertNode(Type item){
            if(this->root>=this->capacity){
                //implement a dynamic array here
                return;
            }
            this->tree[this->root]=item;
            this->root=this->root+1;
        }

        //preorder traversal
        void preOrder(int root){
            if(root>=this->root){
                return;
            }
            cout<<this->tree[root]<<endl;
            preOrder((2*root)+1);
            preOrder((2*root)+2);
        }
        //inorder traversal
        void inOrder(int root){
            if(root>=this->root){
                return;
            }
            inOrder((2*root)+1);
            cout<<this->tree[root]<<endl;
            inOrder((2*root)+2);
        }
        //post order traversal
        void postOrder(int root){
             if(root>=this->root){
                return;
             }
             postOrder(2*root+1);
             postOrder(2*root+2);
             cout<<this->tree[root]<<endl;
        }
};
