//search particular data in linked list
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
        //take input
        int in;
        cin>>in;
        //create node
        nptr=new node;
        nptr->data=in;
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
    

    //test print
    /*
    tptr=root;
    while(true){
        cout<<tptr->data<<endl;
        if(tptr->next==NULL){
            break;
        }
        tptr=tptr->next;

    }
    */

    //search for a data item
    int srch;
    cout<<"SEARCH FOR: ";
    cin>>srch;

    tptr=root;
    while(true){
        if(tptr->data==srch){
             cout<<"FOUND: "<<tptr<<"  "<<tptr->data<<endl;
        }
        if(tptr->next==NULL){
            break;
        }
        tptr=tptr->next;
    }
}
