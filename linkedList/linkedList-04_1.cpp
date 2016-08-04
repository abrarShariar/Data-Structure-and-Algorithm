/*
Add a node before the first node of the list.
*/
#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node* createNode(int item);
void displayList(node* tptr);
node* addFirstNode(node* root);

int main(){
    node *root,*nptr,*tptr;
    root=NULL;

    //takes 3 input
    for(int i=0;i<3;i++){
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


    //insert before first node
    tptr=addFirstNode(root);

    //display list
    displayList(tptr);
}

node* addFirstNode(node* root){
    node* nptr;
    nptr=createNode(100000);
    nptr->next=root;
    root=nptr;
    return root;
}


void displayList(node* root){
     while(true){
        cout<<root->data<<" ";
        if(root->next==NULL){
            break;
        }
        root=root->next;
     }

}
node* createNode(int item){
    node* nptr;
    nptr=new node;
    nptr->data=item;
    nptr->next=NULL;
    return nptr;
}
