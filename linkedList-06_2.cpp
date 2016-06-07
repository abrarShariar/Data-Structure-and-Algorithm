
/*
Delete node in between
*/
#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node* createNode(int item);
void displayList(node* tptr);
void deleteNode(node* tptr,node* temp);

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

    //display list
    cout<<"\nBEFORE DELETION: ";
    tptr=root;
    displayList(tptr);

    //delete node
    cout<<"\nDELETE DATA: ";
    int del;
    cin>>del;
    //search for del position-1
    tptr=root;
    while(true){
        node* temp;
        temp=tptr->next;
        if(temp->data==del){
            //cout<<temp->data<<tptr->data<<endl
            deleteNode(tptr,temp);
            break;
        }
        if(temp->next==NULL){
            break;
        }
        tptr=tptr->next;
    }

    //display linked list
    tptr=root;
    displayList(tptr);
}

void deleteNode(node* tptr,node* temp){
    node* d1;
    d1=temp->next;
    tptr->next=d1;
    delete temp;

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
