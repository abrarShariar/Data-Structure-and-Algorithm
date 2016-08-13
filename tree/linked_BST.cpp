/*
    BST traversal inoredr (linked list)
*/

#include<iostream>
using namespace std;
#define LIMIT 5

struct node{
    int data;
    node* lChild;
    node* rChild;
};

node* createNode(int);
void insertNode(node*,node*);
void inOrder(node*);

int main(){
    node *root,*tptr,*nptr;
    root=NULL;

    //insert node in BST
    for(int i=0;i<LIMIT;i++){
        int item;
        cout<<"Item: ";
        cin>>item;
        nptr=createNode(item);
        if(root==NULL){
            root=nptr;
        }else{
            insertNode(nptr,root);
        }
    }

    //inorder traversal and print
    inOrder(root);
}

void inOrder(node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->lChild);
    cout<<root->data<<endl;
    inOrder(root->rChild);

}

void insertNode(node* nptr,node* root){
    if(root!=NULL){
        if(nptr->data>root->data){
            //go right
            if(root->rChild==NULL){
                root->rChild=nptr;
                return;
            }
            insertNode(nptr,root->rChild);
        }
        else if(nptr->data<root->data){
            //go left
            if(root->lChild==NULL){
                root->lChild=nptr;
                return;
            }
            insertNode(nptr,root->lChild);
        }
    }
}

node* createNode(int item){
    node* nptr=new node;
    nptr->data=item;
    nptr->lChild=NULL;
    nptr->rChild=NULL;
    return nptr;
}
