//linked list implemented with struct
#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

int main(){
    node *root,*nptr,*tptr;
    root=NULL;

    int nodeNum;
    cout<<"Number of Nodes: ";
    cin>>nodeNum;

    for(int i=0;i<nodeNum;i++){
        //input data
        int item;
        cin>>item;
        //create node
        nptr=new node;
        nptr->data=item;
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

    //output

    tptr=root;
    while(true){
        cout<<tptr->data<<" ";
        if(tptr->next==NULL){
            break;
        }
        tptr=tptr->next;
    }
}
