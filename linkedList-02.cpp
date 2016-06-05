#include<iostream>
using namespace std;



struct node{
    int data;
    node *next;
};

node *root,*nptr,*tptr;
node* createNode(int item);
void createLink();
void displayList();

int main(){
    root=NULL;

    for(int i=0;i<5;i++){
        nptr=createNode(i+1);
        createLink();
    }

    //display
    tptr=root;
    displayList();


}

//create new node
node* createNode(int item){
    node *nptr;
    nptr=new node;
    nptr->data=item;
    nptr->next=NULL;
    return nptr;
}

//create link
void createLink(){
    if(root==NULL){
        root=nptr;
        tptr=nptr;
    }else{
        tptr->next=nptr;
        tptr=nptr;
    }
}
//display list
void displayList(){

    while(true){
        cout<<tptr->data<<endl;
        if(tptr->next==NULL){
            break;
        }
        tptr=tptr->next;
    }
}


