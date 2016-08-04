/*

    Doubly linked list method implemented in modular way
*/

#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};


node* createNode(int);
node* makeLinkedList(node*,int);
void inorderPrint(node*);
node* insertNode(node*,int,int);
node* deleteNode(node*,int);

int main(){
    node *root,*tptr,*nptr,*tail;
    root=NULL;
    tail=root;
    int length=5;
    //cin>>len;
    root=makeLinkedList(tail,length);
    //before insert
    cout<<"Doubly Linked List: ";
    inorderPrint(root);

    //insert node
    int pos,data;
    cout<<"\nInsert Position: ";
    cin>>pos;
    cout<<"Insert Data: ";
    cin>>data;
    //of insert head
    root=insertNode(root,data,pos);
    cout<<"\nAfter Insertion : "<<endl;
    inorderPrint(root);

    //cout<<root->data<<endl;
    cout<<"\n\nDelete Data: "<<endl;
    cin>>data;
    root=deleteNode(root,data);
    cout<<"\nAfter Deletion: "<<endl;
    inorderPrint(root);
}

node* deleteNode(node* root,int data){
    node *tptr;
    tptr=root;
    //if delete at head
    if(root->data==data){
        root=root->next;
        delete tptr;
        return root;
    }

    while(tptr->data!=data){
        tptr=tptr->next;
    }
    //cout<<tptr->data<<endl;
    //delete last node
    if(tptr->next==NULL){
        tptr=tptr->prev;
        delete tptr->next;
        return root;
    }

    //delete at nth
    tptr->next->prev=tptr->prev;
    tptr->prev->next=tptr->next;
    delete tptr;
    return root;
}

node* insertNode(node* root,int data,int pos){
    node *nptr,*tptr;
    tptr=root;
    nptr=createNode(data);
    if(pos==1){
        root->prev=nptr;
        nptr->next=root;
        root=nptr;
        return root;
    }

    for(int i=0;i<pos-1;i++){
        //if element to insert in last pos
        if(tptr->next==NULL){
            tptr->next=nptr;
            nptr->prev=root;
            return root;
        }
        tptr=tptr->next;
    }


    //cout<<root->data<<endl;
    //insert node data in pos
    tptr->prev->next=nptr;
    nptr->prev=tptr->prev;
    nptr->next=tptr;
    tptr->prev=nptr;

    return root;
}

void inorderPrint(node* root){
    if(root==NULL){
        cout<<"Linked List Empty"<<endl;
        return;
    }
    while(root!=NULL){
        cout<<root->data<<" ";
        root=root->next;
    }
}

node* makeLinkedList(node* tail,int length){
    node *nptr,*root,*tptr;
    root=NULL;
    //tptr=root;
    for(int i=0;i<length;i++){
        nptr=createNode((i+1)*10);
        if(root==NULL){
            root=nptr;
            tail=nptr;
            continue;
        }
        tail->next=nptr;
        nptr->prev=tail;
        tail=nptr;
    }
    //cout<<tail->data<<endl;
    return root;
}

node* createNode(int item){
    node *nptr;
    nptr=new node;
    nptr->data=item;
    nptr->next=NULL;
    nptr->prev=NULL;
    return nptr;
}
