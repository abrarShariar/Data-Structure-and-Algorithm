#include<iostream>
#include "Queue.h"
#include<queue>
using namespace std;

//A binary tree
struct node{
    int data;
    node* left;
    node* right;
};

void printLevelOrder(node*);
node* createNode(int);

int main(){

    node* root=createNode(10);
    root->left=createNode(20);
    root->right=createNode(30);
    root->left->left=createNode(40);
    root->left->right=createNode(50);

    cout<<"Level Order Traversal of binary tree: "<<endl;
    printLevelOrder(root);


/*
    MY QUEUE
    node *nptr;
    Queue<node*>que(10);
    nptr=createNode(10);
    que.enQueue(nptr);
    nptr=createNode(20);
    que.enQueue(nptr);
    nptr=createNode(30);
    que.enQueue(nptr);
//    nptr=que.deQueue();
//    cout<<nptr->data<<endl;
    while(!que.isEmpty()){
        nptr=que.deQueue();
        cout<<nptr->data<<endl;
    }
    */
}

//iterative method
void printLevelOrder(node* root){
    //Base case
    if(root==NULL){
        return;
    }

    //create an empty queue
    Queue<node*>que(10);
    que.enQueue(root);

    while(!que.isEmpty()){
        node* tptr=que.deQueue();
        cout<<tptr->data<<endl;

        //enqueue left child
        if(tptr->left!=NULL){
            que.enQueue(tptr->left);
        }

        //enqueue right child
        if(tptr->right!=NULL){
            que.enQueue(tptr->right);
        }
        //pop the first item
        //q.pop();
    }
}

//create a new node
node* createNode(int item){

    node* nptr;
    nptr=new node;
    nptr->data=item;
    nptr->left=nptr->right=NULL;
    return nptr;
}
