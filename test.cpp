#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};


int main(){
    node *root,*tptr,*nptr;


}






//singly linked list delete
/*
int main(){
    node *root,*tptr,*nptr;
    root=NULL;
    for(int i=0;i<5;i++){
        nptr=new node;
        nptr->data=i+1;
        nptr->next=NULL;
        if(root==NULL){
            root=nptr;
            tptr=nptr;
            continue;
        }
        tptr->next=nptr;
        tptr=nptr;
    }

    //test output
    cout<<"Before Delete: "<<endl;
    tptr=root;
    while(tptr!=NULL){
        cout<<tptr->data<<" ";
        tptr=tptr->next;
    }
    cout<<endl;
    //delete
    tptr=root;
    int delData;
    cin>>delData;
    while(tptr!=NULL){
        if(root->data==delData){
            root=root->next;
            delete tptr;
            break;
        }
        if(tptr->next->data==delData){
            tptr->next=tptr->next->next;
            break;
        }
        tptr=tptr->next;
    }

    //test output
    tptr=root;
    while(tptr!=NULL){
        cout<<tptr->data<<" ";
        tptr=tptr->next;
    }
}
*/
