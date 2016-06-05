#include<iostream>
using namespace std;


struct node{
    int data;
    node *next;
};

void displayList(node *root);
int main(){

    node *root,*nptr,*tptr;
    root=NULL;

//take input
    for(int i=0;i<3;i++){
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

//display old linked list
    //displayList(root);

    //insert data in between 1st and 2nd position
    tptr=root;
    nptr=new node;
    nptr->data=2;
    nptr->next=NULL;

    node *temp;
    temp=tptr->next;

    tptr->next=nptr;
    tptr=nptr;
    tptr->next=temp;

    //cout<<tptr->data<<endl;
/*    tptr->next=nptr;
    nptr->next*=
*/

    displayList(root);

}

void displayList(node *root){
    node *tptr;
    tptr=root;
    while(true){
        cout<<tptr->data<<endl;
        if(tptr->next==NULL){
            break;
        }
        tptr=tptr->next;
    }

}
