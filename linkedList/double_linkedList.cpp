/*
    DOUBLY LINKED LIST
*/
#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};

node* createNode(int item);
void inOrderPrint(node* root);
void reverseOrderPrint(node* tail);
void insertNode(node* tptr,int item);

int main(){
    node *root,*nptr,*tptr,*tail;
    root=NULL;

    //create 5 nodes (input in ASC)
    for(int i=0;i<5;i++){
        int item;
        cin>>item;
        nptr=createNode(item);
        if(root==NULL){
            root=nptr;
            tptr=nptr;
        }else{
            nptr->prev=tptr;
            tptr->next=nptr;
            tptr=nptr;
        }
    }

    //set tail
    tail=tptr;
    tptr=root;

    //insert new node
    //insertNode(tptr,15);      //bug

    //in order print
    cout<<"In Order :"<<endl;
    inOrderPrint(tptr);
    cout<<"Reverse Order: "<<endl;
    reverseOrderPrint(tail);
}

void insertNode(node* tptr,int item){
    node *nptr,*btptr,*etptr;
    nptr=createNode(item);

    while(true){
        etptr=tptr->next;
        btptr=tptr->prev;
        if(etptr==NULL){
            break;
        }
        if(btptr->data<nptr->data && etptr->data>=nptr->data){
            tptr->next=nptr;
            etptr->prev=nptr;
            break;
        }
    }
}

void reverseOrderPrint(node* tail){
    while(true){
        cout<<tail->data<<endl;
        if(tail->prev==NULL){
            break;
        }
        tail=tail->prev;
    }

}

void inOrderPrint(node* root){
    while(true){
        cout<<root->data<<endl;
        if(root->next==NULL){
            break;
        }
        root=root->next;
    }
}

node* createNode(int item){
    node* nptr;
    nptr=new node;
    nptr->data=item;
    nptr->next=NULL;
    nptr->prev=NULL;
    return nptr;
}
