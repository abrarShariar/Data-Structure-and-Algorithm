
/*
Inset a node in between two existing nodes of the list.
*/
#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node* createNode(int item);
void displayList(node* tptr);
void insertNodeAfter(node *tptr);

int main(){
    node *root,*nptr,*tptr;
    root=NULL;

    cout<<"Values for 4 nodes: "<<endl;
    //takes 4 input
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

    //insert node between existing nodes
    tptr=root;
    int input;
    cout<<"\nINSERT AFTER: ";
    cin>>input;
    while(true){
        if(tptr->data==input){
            insertNodeAfter(tptr);
            break;
        }
        if(tptr->next==NULL){
            break;
        }
        tptr=tptr->next;
    }



    //display list
    tptr=root;
    displayList(tptr);
}

void insertNodeAfter(node* tptr){
    int item;
    cout<<"\nINSERT VALUE: ";
    cin>>item;

    node* nptr;
    nptr=createNode(item);

    node* temp;
    temp=tptr->next;

    tptr->next=nptr;
    nptr->next=temp;
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
