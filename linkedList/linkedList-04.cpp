
#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node* createNode(int item);
void displayList(node *root);
node* insertLastNode(node *root,node *tptr,int item);

int main(){
    node *root,*nptr,*tptr;
    root=NULL;

    for(int i=0;i<3;i++){
        int item;
        cin>>item;
        //create node
        nptr=createNode(item);
        //create link
        if(root==NULL){
            root=nptr;
            tptr=nptr;
        }else{
            tptr->next=nptr;
            tptr=nptr;
        }
    }

    //display old list
    cout<<"OLD LIST: ";
    displayList(root);
    cout<<endl;

    //insert after last node
    tptr=root;
    while(true){
        if(tptr->next==NULL){
            root=insertLastNode(root,tptr,100000);
            break;
        }
        tptr=tptr->next;
    }
    cout<<"NEW LIST: ";
    displayList(root);
    cout<<endl;

}

//insert new node before first
node* insertLastNode(node *root,node *tptr,int item){
    node *nptr;
    nptr=createNode(100000);
    tptr->next=nptr;

    tptr=root;
    return tptr;
}

//create new node
node* createNode(int item){
    node *nptr;
    nptr=new node;
    nptr->data=item;
    nptr->next=NULL;
}

//display linked list
void displayList(node *root){
    node *tptr;
    tptr=root;
    while(true){
        cout<<tptr->data<<" ";
        if(tptr->next==NULL){
            break;
        }
        tptr=tptr->next;
    }
}
