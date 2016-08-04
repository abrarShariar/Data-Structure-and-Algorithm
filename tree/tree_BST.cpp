/*
    A Lannister always pays his debts
    BST
    Binary Search Tree implemented using C++

    - INSERT
    - SEARCH
*/

#include<iostream>
using namespace std;

struct node{
    int data;
    node* leftNode;
    node* rightNode;
};

node* createNode(int);
void insertNode(node*,node*);
int searchNode(node*,int);

int main(){
    node *root,*tptr,*nptr;
    int input;
    root=NULL;
    //take input
    int num;
    cout<<"How many nodes you want to create: ";
    cin>>num;

    for(int i=0;i<num;i++){
        cin>>input;
        nptr=createNode(input);     //create a new node
        if(root==NULL){
            root=nptr;
        }else{
            insertNode(root,nptr);
        }
    }

    //search node
    cout<<"SEARCH: ";
    cin>>input;
    int found=NULL;

    if(root->data==input){
        found=root->data;
    }else{
        found=searchNode(root,input);
    }

    if(found==NULL){
        cout<<"NOT FOUND"<<endl;
    }else{
        cout<<"FOUND: ";
        cout<<found<<endl;
    }
}

//search for a particular node
int searchNode(node* root,int element){
    node* temp;
    //if end reached
    if(root==NULL){
        return NULL;
    }

    if(element>root->data){
        //right node traverse
        temp=root->rightNode;
        if(temp==NULL){
            return NULL;
        }
        if(temp->data==element){
            return temp->data;
        }
        root=temp;
    }else{
        //left node traverse
        temp=root->leftNode;
        if(temp==NULL){
            return NULL;
        }
        if(temp->data==element){
            return temp->data;
        }
        root=temp;
    }
    searchNode(root,element);       //recursive call
}

//insert node in right position
void insertNode(node *root,node *nptr){
    //node* temp;
    if(nptr->data>root->data){
        //right sub tree
        if(root->rightNode==NULL){
            root->rightNode=nptr;
            return;
        }
        root=root->rightNode;
    }else{
        //left sub tree
        if(root->leftNode==NULL){
            //temp=nptr;
            root->leftNode=nptr;
            return;
        }
        root=root->leftNode;
    }
    insertNode(root,nptr);      //recursive call
}

node* createNode(int item){
    node *nptr;
    nptr=new node;
    nptr->data=item;
    nptr->leftNode=NULL;
    nptr->rightNode=NULL;
    return nptr;
}
