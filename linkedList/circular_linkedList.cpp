/*
    circular linked list implementation
*/
#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* createNode(int);
node* insertNode(node*,node*);
void printCircular(node*,int);


int main(){
    node *root,*tptr,*nptr,*tail;
    root=NULL;
    tail=root;
    int limit,item,times;
    //cout<<"Number of Nodes: ";
    cin>>limit;
    for(int i=0;i<limit;i++){
    //create node and insert into circular linked list
        //cout<<"ITEM: ";
        cin>>item;
        nptr=createNode(item);
        if(root==NULL && tail==NULL){
            root=nptr;
            tail=root;
        }
        else{
            tail=insertNode(tail,nptr);
            tail->next=root;
        }
    }

    //cout<<"How many items to print: ";
    cin>>times;
    printCircular(root,times);

/*
    tptr=root;
    //test print
    while(true){
        if(tptr->next==root){
            cout<<tptr->data<<endl;
            break;
        }
        cout<<tptr->data<<endl;
        tptr=tptr->next;
    }
*/
}

void printCircular(node* root,int times){
    for(int i=0;i<times;i++){
        cout<<root->data<<" ";
        root=root->next;
    }
}

node* insertNode(node* tail,node* newNode){
    tail->next=newNode;
    tail=newNode;
    return tail;
}


node* createNode(int item){
    node* nptr;
    nptr=new node;
    nptr->data=item;
    nptr->next=NULL;
    return nptr;
}
