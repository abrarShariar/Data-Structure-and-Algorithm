/*
    Reverse print using linked list
*/
#include<iostream>
#include<cstdio>
using namespace std;

struct node{
    char data;
    node* next;
};

node* createNode(char item);
node* push(node* root,char item);
node* pop(node* root,char* popItem);

int main(){
    node *root,*tptr,*nptr;
    root=NULL;

    //take input
    cout<<"INPUT: "<<endl;
    while(true){
        char input;
        input=getchar();
        if(input=='$'){
            break;
        }
        root=push(root,input);
    }

    tptr=root;
    //show in DESC (POP)
    cout<<"\nOUTPUT: "<<endl;


    while(true){
        char popItem;
        tptr=pop(tptr,&popItem);
        cout<<popItem;
        if(tptr==NULL){
            //cout<<"STACK EMPTY"<<endl;
            break;
        }
    }
}

node* pop(node* root,char* popItem){
    *popItem=root->data;
    node* tptr;
    tptr=root;
    root=tptr->next;
    delete tptr;
    return root;
}

node* push(node* root,char item){
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

node* createNode(char item){
    node* nptr;
    nptr=new node;
    nptr->data=item;
    nptr->next=NULL;
    return nptr;
}

