#include<iostream>
using namespace std;

struct node{
        int data;
        node* next;
    };
node* createNode(int item);

int main(){
    node *root,*tptr,*nptr;
    root=NULL;

    //insert 5 nodes
    for(int i=0;i<5;i++){
        nptr=createNode((i+1)*10);
        if(root==NULL){
            root=nptr;
            tptr=nptr;
        }else{
            tptr->next=nptr;
            tptr=nptr;
        }
    }

    tptr=root;
    //print
    while(tptr!=NULL){
        cout<<tptr->data<<endl;
        tptr=tptr->next;
    }
}

node* createNode(int item){
    node *nptr;
    nptr=new node;
    nptr->data=item;
    nptr->next=NULL;
    return nptr;
}
