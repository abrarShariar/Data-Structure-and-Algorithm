/*
    CIRCULAR QUEUE implemented using linked list
*/

#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* createNode(int);

int main(){
    node *root,*tail,*nptr,*tptr;
    root=NULL;
    tail=root;
    int item,limit;

    //cout<<"Total number of items to enqueue: ";
    cin<<limit;
    for(int i=0;i<limit;i++){
        //cout<<"Item: ";
        cin>>item;
        nptr=createNode(item);
        if(root==NULL && tail==NULL){
            root=nptr;
            tail=root;
        }else{
            enqueue(tail,nptr);
        }

    }
}

node* createNode(int item){
    node* nptr;
    nptr=new node;
    nptr->data=item;
    nptr->next=NULL;
    return nptr;
}

