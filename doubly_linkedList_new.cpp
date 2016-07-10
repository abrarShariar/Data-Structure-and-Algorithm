/*
    SLIPKNOT - youtube - playlist

    Doubly Linked List methods implemented in C++

    - create doubly linked list
    - print in order
    - print in reverse order
    - Insert element in nth position
    - Delete element in nth position
*/

#include<iostream>
using namespace std;

#define LIMIT 5

struct node{
    int data;
    node *next;
    node *prev;
};

node* createNode(int);
void printInOrder(node*);
void printReverseOrder(node*);
void insertNode(node*,int,int);
void deleteNode(node*,int);


int main(){
    node *root,*tail,*nptr,*tptr;
    root=NULL;

    cout<<"INPUT :"<<endl;
    //take 5 user input
    int item;
    for(int i=0;i<LIMIT;i++){
        cin>>item;
        nptr=createNode(item);
        if(root==NULL){
            root=nptr;
            tail=nptr;
        }else{
            tail->next=nptr;
            nptr->prev=tail;
            tail=nptr;
        }
    }

    //print in order
    cout<<"\nPRINT IN ORDER: ";
    printInOrder(root);

    //print in reverse order
    cout<<"\nPRINT REVERSE ORDER: ";
    printReverseOrder(tail);

    //insert in nth pos
    int pos;
    cout<<"\n\nINSERT DATA: ";
    cin>>item;
    cout<<"\n\nINSERT POS: ";
    cin>>pos;

    if(pos==0){
        nptr=createNode(item);
        nptr->next=root;
        root->prev=nptr;
        root=nptr;
    }else if(pos>=LIMIT){
        nptr=createNode(item);
        nptr->prev=tail;
        tail->next=nptr;
        tail=nptr;
    }else{
        insertNode(root,item,pos);
    }

    //insertNode(root,item,pos);
    //print after insertion
    cout<<"\nAfter Insertion: ";
    printInOrder(root);
    cout<<"\n"<<endl;

    cout<<"\nDelete Node Position: ";
    cin>>pos;
    tptr=root;
    if(pos==0){
        root=tptr->next;
        delete tptr;
    }else{
        deleteNode(root,pos);
    }

    cout<<"\nAfter Deletion: ";
    printInOrder(root);
    cout<<endl;
}

void deleteNode(node* root,int pos){
    if(root==NULL){
        cout<<"Linked List Empty"<<endl;
        return;
    }

    for(int i=0;i<pos;i++){
        root=root->next;
    }

    node* tptr;
    tptr=root->prev;
    tptr->next=root->next;
    root->next=root->prev;
}

void insertNode(node* root,int item,int pos){
    node *tptr,*nptr;
    nptr=createNode(item);
    if(root==NULL){
        root=nptr;
        return;
    }

    for(int i=0;i<pos;i++){
        root=root->next;
    }

    //link up new node
    nptr->prev=root->prev;
    nptr->next=root;
    root->prev=nptr;
    root=nptr->prev;
    root->next=nptr;
}

void printReverseOrder(node* tail){
    while(tail!=NULL){
        cout<<tail->data<<" ";
        tail=tail->prev;
    }
}

void printInOrder(node* root){
    if(root==NULL){
        cout<<"LINKED LIST EMPTY"<<endl;
        return;
    }
    while(root!=NULL){
        cout<<root->data<<" ";
        root=root->next;
    }
}

node* createNode(int item){
    node *nptr;
    nptr=new node;
    nptr->data=item;
    nptr->next=NULL;
    nptr->prev=NULL;
    return nptr;
}
