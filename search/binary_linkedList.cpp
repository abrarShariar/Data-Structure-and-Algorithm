/*
  binary search of a sorted singly linked list
  O(log N)
*/
#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

int binarySearch(node*,int);

int main(){
    node *root,*tptr,*nptr;
    root=NULL;

    for(int i=10;i<=15;i++){
        nptr=new node;
        nptr->data=i;
        nptr->next=NULL;
        if(root==NULL){
            root=nptr;
            tptr=nptr;
        }else{
            tptr->next=nptr;
            tptr=nptr;
        }
    }

    //take input for search
    int in;
    cin>>in;
    binarySearch(root,in);
}

int binarySearch(node* root,int in){


}
