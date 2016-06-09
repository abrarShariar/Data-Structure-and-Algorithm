#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* createNode(int item);
node* push(node* root,int value);
node* pop(node* root);
void showStack(node* tptr);

int main(){
    node *root,*nptr,*tptr;
    root=NULL;

    for(int i=0;i<5;i++){
        nptr=createNode(i+1);
        if(root==NULL){
            root=nptr;
            tptr=nptr;
        }else{
            tptr->next=nptr;
            tptr=nptr;
        }
    }

    cout<<"Before Push: "<<endl;
    showStack(root);

    cout<<"After Push: "<<endl;
    tptr=root;
    for(int i=0;i<3;i++){
        int value=(i+1)*100;
        tptr=push(tptr,value);
    }

     showStack(tptr);
    //tptr=root;
    cout<<"\nAfter Pop"<<endl;
    tptr=pop(tptr);
    showStack(tptr);
}

node* pop(node* root){
    node* tptr;
    tptr=root;
    root=tptr->next;
    delete tptr;
    return root;
}

node* push(node* root,int value){
    node* tptr;
    tptr=root;
    node* nptr;
    nptr=createNode(value);
    root=nptr;
    nptr->next=tptr;
    return root;
}

node* createNode(int item){
    node* nptr;
    nptr=new node;
    nptr->data=item;
    nptr->next=NULL;
    return nptr;
}

void showStack(node* tptr){
    while(true){
        cout<<tptr->data<<endl;
        if(tptr->next==NULL){
            break;
        }
        tptr=tptr->next;
    }
}
