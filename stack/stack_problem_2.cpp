/*
    Problem 1 solved using linked list
*/
#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* createNode(int item);
node* push(node* root,int item);
node* pop(node* root,int* popItem);

int main(){
    node *root,*tptr,*nptr;
    root=NULL;

    //push 10 integers in ASC
    cout<<"PUSH 10 integers in ASC: "<<endl;
    for(int i=0;i<10;i++){
        int item;
        cin>>item;
        root=push(root,item);
    }

    tptr=root;
    //show in DESC (POP)
    cout<<"DESC: "<<endl;


    while(true){
        int popItem;
        tptr=pop(tptr,&popItem);
        cout<<popItem<<endl;
        if(tptr==NULL){
            cout<<"STACK EMPTY"<<endl;
            break;
        }
    }
}

node* pop(node* root,int* popItem){
    *popItem=root->data;
    node* tptr;
    tptr=root;
    root=tptr->next;
    delete tptr;
    return root;
}

node* push(node* root,int item){
    node* nptr;
    nptr=createNode(item);
    if(root==NULL){
        root=nptr;
    }else{
        nptr->next=root;
        root=nptr;
    }

    return root;
}

node* createNode(int item){
    node* nptr;
    nptr=new node;
    nptr->data=item;
    nptr->next=NULL;
    return nptr;
}
