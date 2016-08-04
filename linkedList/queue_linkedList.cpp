#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* createNode(int item);
void enQueue(int item);
int deQueue();

node *root,*tail;
int main(){
    root=NULL;
    tail=root;

    enQueue(1000);
    enQueue(2000);
    enQueue(3000);

    cout<<"DEQUEUE: "<<endl;
    while(true){
        int item=deQueue();
        if(item==NULL){
            break;
        }
        cout<<item<<endl;
    }
}

//get item from front of queue and delete
int deQueue(){
    if(root==NULL){
        cout<<"QUEUE EMPTY"<<endl;
        return NULL;
    }
    node *tptr;
    int item;
    item=root->data;
    tptr=root->next;
    delete root;
    root=tptr;
    return item;
}

node* createNode(int item){
    node* nptr;
    nptr=new node;
    nptr->data=item;
    nptr->next=NULL;
    return nptr;
}

//insert item into tail of queue
void enQueue(int item){
    node* nptr;
    nptr=createNode(item);
    if(root==NULL){
        root=nptr;
        tail=nptr;
    }else{
        tail->next=nptr;
        tail=nptr;
    }
}


