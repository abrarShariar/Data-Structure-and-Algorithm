#include<iostream>
using namespace std;


struct node{
    int data;
    node* next;
}

node* createNode(int);

int main(){
    node *root,*tptr,*nptr;
    root=NULL;

    for(int i=0;i<10;i++){
        if(root==NULL){
            root=nptr;
            tptr=nptr;
        }else{
            insertNode(tptr,);
        }

    }

}

insertNode(node* tptr,node* nptr){
    node* nptr;
    nptr=createNode()
}

node* createNode(int item){
    node* nptr;
    nptr=new node;
    nptr->data=item;
    nptr->next=NULL;
    return nptr;
}
