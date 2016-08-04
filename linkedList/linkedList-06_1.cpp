//Delete the first node of the linked list.

#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node* createNode(int item);
void displayList(node* tptr);
node* deleteFirstNode(node* tptr);

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
    root=deleteFirstNode(tptr);

    //display linked list
    tptr=root;
    cout<<"\nAFTER DELETION: ";
    displayList(tptr);
}

node* deleteFirstNode(node* tptr){
    node* temp;
    temp=tptr->next;

    node* root;
    root=temp;
    delete tptr;

    return root;
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
