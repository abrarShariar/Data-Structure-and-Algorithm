/*
Sort in ASC
*/
#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node* createNode(int item);
void displayList(node* tptr);

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

    //sorting ASC....
    bool isSort=false;
    while(!isSort){
        tptr=root;
        isSort=true;
        for(int i=0;i<3;i++){
            node *temp;
            temp=tptr->next;
            if(tptr->data > temp->data){
                isSort=false;
                int item;
                item=tptr->data;
                tptr->data=temp->data;
                temp->data=item;
            }
            tptr=tptr->next;
        }
    }

    //display linked list
    tptr=root;
    displayList(tptr);
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

