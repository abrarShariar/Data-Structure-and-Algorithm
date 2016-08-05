/*

    PRIORITY QUEUE implemented with linked list
    - ENQUEUE
    - DEQUEUE
*/

#include<iostream>
using namespace std;

#define LIMIT 5

struct node{
    string data;
    int priority;
    node* next;
};

node* createNode(string,int);
void enqueue(node*,node*);
string dequeue(node*);
void printQueue(node*);


int main(){
    node *root,*nptr,*tptr,*tail;
    root=NULL;
    tail=root;
    int p;
    string str;
    //take input Data and Priority
    for(int i=0;i<LIMIT;i++){
        cout<<"\nItem: ";
        getline(cin,str);
        cout<<"Priority: ";
        cin>>p;
        cin.ignore(256,'\n');

        //create node
        nptr=createNode(str,p);
        //insert node in queue
        if(root==NULL){
            root=nptr;
            //tail=nptr;
        }else{
            enqueue(root,nptr);
        }
    }

    //dequeue all
    tptr=root;
    while(tptr!=NULL){
        cout<<dequeue(tptr)<<endl;
        tptr=tptr->next;
    }

    //test print
    //printQueue(root);
}

string dequeue(node* root){
    node* tptr;
    tptr=root;
    string item=tptr->data;
    root=root->next;

    delete tptr;
    tptr=NULL;
    return item;
}

void printQueue(node* root){

    while(root!=NULL){
        cout<<root->data<<endl;
        root=root->next;
    }
}


void enqueue(node* root,node* nptr){
        //node* tptr;
        if(root->next==NULL){
            if(root->priority < nptr->priority){
                root->next=nptr;
            }else{
                nptr->next=root;
                root=nptr;
            }
            return;
        }

        while(root!=NULL){
            if(root->priority < nptr->priority && root->next!=NULL){
                if(root->next->priority > nptr->priority){
                    nptr->next=root->next;
                    root->next=nptr;
                    return;
                }
            }
            if(root->priority < nptr->priority && root->next==NULL){
                root->next=nptr;
                return;
            }
            root=root->next;
        }

}


node* createNode(string data,int priority){
        node* nptr=new node;
        nptr->data=data;
        nptr->priority=priority;
        nptr->next=NULL;
        return nptr;
}
