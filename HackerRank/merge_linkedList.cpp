#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* MergeLists(node*,node*);

int main(){
    node *headA,*headB,*tptrA,*tptrB,*nptr;
    headA=NULL;
    headB=NULL;
    //node 01 insert elements
    for(int i=1;i<=7;i+=2){
        nptr=new node;
        nptr->data=i;
        nptr->next=NULL;
        if(headA==NULL){
            headA=nptr;
            tptrA=nptr;
        }else{
            tptrA->next=nptr;
            tptrA=nptr;
        }
    }

    //node 02 insert elements
    for(int i=2;i<=6;i+=2){
        nptr=new node;
        nptr->data=i;
        nptr->next=NULL;
        if(headB==NULL){
            headB=nptr;
            tptrB=nptr;
        }else{
            tptrB->next=nptr;
            tptrB=nptr;
        }
    }


    //test output node 1
    /*
    while(headA!=NULL){
        cout<<headA->data<<" ";
        headA=headA->next;
    }
    cout<<endl;
    //test output node 2
    while(headB!=NULL){
        cout<<headB->data<<" ";
        headB=headB->next;
    }
    */


    node *newRoot;
    newRoot=MergeLists(headA,headB);

    //test print
    //cout<<newRoot->data<<endl;

    while(newRoot!=NULL){
        cout<<newRoot->data<<endl;
        newRoot=newRoot->next;
    }


}

node* MergeLists(node* headA,node* headB){
    node *tptr,*tail;
    tptr=headA;
    tail=headA;

    while(tptr!=NULL){
        tail=tptr;
        tptr=tptr->next;
    }
    //cout<<tail->data<<endl;
    tptr=headB;
    while(tptr!=NULL){
        tail->next=tptr;
        tail=tail->next;
        tptr=tptr->next;
    }
    //cout<<tail->data<<endl;
    //sort in ASC
    tptr=headA;
    bool isSort=false;
    while(!isSort){
        tptr=headA;
        isSort=true;
        while(tptr!=NULL){
            //isSort=true;
            if(tptr->data > tptr->next->data){
                int temp;
                temp=tptr->next->data;
                tptr->next->data=tptr->data;
                tptr->data=temp;
               //tptr=tptr->next;
                isSort=false;
            }
            tptr=tptr->next;
        }
    }
    //cout<<tptr->data<<endl;
    return headA;
}
