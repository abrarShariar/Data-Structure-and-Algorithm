/*
Add a node at the end of the list.
*/
#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node* createNode(int item);
void displayList(node* tptr);
void insertEndNode(node* tptr,int item);

int main(){
    node *root,*nptr,*tptr;
    root=NULL;

    cout<<"ENTER VALUES FOR 4 NODES: "<<endl;
    //create linked list
    for(int i=0;i<4;i++){
        int item;
        cin>>item;
        nptr=createNode(item);
        if(root==NULL){
            root=nptr;
            tptr=nptr;
        }else{
            tptr->next=nptr;
            tptr=nptr;
        }
    }

    //insert at the end
    insertEndNode(root,100000);

    //display list
    tptr=root;
    displayList(tptr);
}

void insertEndNode(node* tptr,int item){
    while(true){
        if(tptr->next==NULL){
            //adding node at end
            node *nptr;
            nptr=createNode(item);
            tptr->next=nptr;
            break;
        }
        tptr=tptr->next;
    }

}

node* createNode(int item){
    node* nptr;
    nptr=new node;
    nptr->data=item;
    nptr->next=NULL;
    return nptr;
}

void displayList(node* tptr){
    while(true){
        cout<<tptr->data<<" ";
        if(tptr->next==NULL){
            break;
        }
        tptr=tptr->next;
    }
}
