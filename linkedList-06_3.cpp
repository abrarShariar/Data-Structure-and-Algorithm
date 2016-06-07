/*
Delete the last node of the list.
*/
#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node* createNode(int item);
void displayList(node* tptr);
void deleteLastNode(node* tptr);

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

    tptr=root;
    //display list
    cout<<"\nBEFORE DELETION: ";
    displayList(tptr);

    //delete first node
    deleteLastNode(tptr);

    //display linked list
    tptr=root;
    cout<<"\nAFTER DELETION: ";
    displayList(tptr);
}

//delete the first node and change root
void deleteLastNode(node* tptr){
    node* temp;
    while(true){
        temp=tptr->next;
        if(temp->next==NULL){
            delete temp;
            tptr->next=NULL;
            break;
        }
        tptr=tptr->next;
    }
}

//create a new node and return its ref
node* createNode(int item){
    node* nptr;
    nptr=new node;
    nptr->data=item;
    nptr->next=NULL;
    return nptr;
}

//function to display a linked list when root is passed
void displayList(node* tptr){
    while(true){
        cout<<tptr->data<<" ";
        if(tptr->next==NULL){
            break;
        }
        tptr=tptr->next;
    }
}

