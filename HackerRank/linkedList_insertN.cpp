#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* insertNode(node*,int,int);

int main(){
    node *root,*nptr,*tptr;
    root=NULL;

    for(int i=0;i<5;i++){
        nptr=new node;
        nptr->data=i+1;
        nptr->next=NULL;
        if(root==NULL){
            root=nptr;
            tptr=nptr;
        }else{
            tptr->next=nptr;
            tptr=nptr;
        }
    }

    //print linked list
    tptr=root;
    while(tptr!=NULL){
        cout<<tptr->data<<endl;
        tptr=tptr->next;
    }

    int pos;
    cin>>pos;
    root=insertNode(root,999,pos);
    cout<<endl;

    while(root!=NULL){
        cout<<root->data<<endl;
        root=root->next;
    }
}

node* insertNode(node* root,int item,int pos){
    node *nptr;
    nptr=new node;
    nptr->data=item;
    nptr->next=NULL;

    if(root==NULL){
        root=nptr;
        return root;
    }
    if(pos==0){
        nptr->next=root;
        root=nptr;
        return root;
    }

    node *tptr;
    tptr=root;
    for(int i=0;i<pos-1;i++){
        //tptr=tptr->next;
        tptr=tptr->next;
    }

    nptr->next=tptr->next;
    tptr->next=nptr;

    return root;
}
