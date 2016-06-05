#include<iostream>
using namespace std;


struct node{
    int data;
    node *next;
};
int main(){
    node *root,*nptr,*tptr;
    root=NULL;

    for(int i=0;i<5;i++){
        //create node
        nptr=new node;
        nptr->data=i+1;
        nptr->next=NULL;
        //create link
        if(root==NULL){
            root=nptr;
            tptr=nptr;
        }else{
            tptr->next=nptr;
            tptr=nptr;
        }
    }

    //display linked list
    tptr=root;
    while(true){
        cout<<tptr->data<<endl;
        if(tptr->next==NULL){
            break;
        }
        tptr=tptr->next;
    }
}
