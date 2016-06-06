#include<iostream>
using namespace std;


struct node{
    int data;
    node *next;
};

void displayList(node* tptr);
node* createNode(int item);
node* createLink(node* tptr,node* nptr);

int main(){
    node *root,*nptr,*tptr;
    root=NULL;

    for(int i=0;i<5;i++){
        //create new node
        nptr=createNode(i+1);
        //create link
        if(root==NULL){
            root=nptr;
            tptr=nptr;
        }else{
            tptr=createLink(tptr,nptr);
        }
    }

    //display list
    tptr=root;
    displayList(tptr);
}

node* createLink(node* tptr,node* nptr){
       tptr->next=nptr;
       tptr=nptr;
       return tptr;
}

node* createNode(int item){
    node *nptr;
    nptr=new node;
    nptr->data=item;
    nptr->next=NULL;
    return nptr;
}


void displayList(node *tptr){
    while(true){
        cout<<tptr->data<<" ";
        if(tptr->next==NULL){
            break;
        }
        tptr=tptr->next;
    }

}



