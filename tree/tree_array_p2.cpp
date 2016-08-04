//complete binary tree implemented using dynamic array

/*
    code only work for complete binary tree
*/

#include<iostream>
using namespace std;
//complete binary tree with 11 nodes
#define LIMIT 11    //max nodes

int capacity=5;      //size of initial array
int sz=0;
int *dynamic;   //pointer to dynamic array
int countNode=0;

void insertNode(int,int);
void printLeftTree(int);
void printRightTree(int);

int main(){

    int in,lChild,rChild;

    int *arr=new int[capacity];
    dynamic=arr;
    //initialize array
    for(int i=0;i<capacity;i++){
        dynamic[i]=-1;
    }

    //root insert
    int root=0;
    cout<<"ROOT: ";
    cin>>in;
    dynamic[root]=in;
    countNode++;
    //take input
    while(countNode<LIMIT){
        if(dynamic[root]==-1 || dynamic[root]==NULL){
            break;
        }
        cout<<"\n\t["<<dynamic[root]<<"]"<<endl;
        cout<<"LEFT CHILD: ";
        cin>>lChild;
        //-1 for no value
        if(lChild!=-1){
            insertNode(lChild,((2*root)+1));
            countNode++;
        }

        cout<<"RIGHT CHILD: ";
        cin>>rChild;
        if(rChild!=-1){
            insertNode(rChild,(2*root)+2);
            countNode++;
        }
        root++;
    }


    //print leftmost sub tree
    cout<<"\nLEFT SUB TREE:"<<endl;
    printLeftTree(1);
    cout<<"\nRIGHT SUB TREE:"<<endl;
    printRightTree(2);

    //DEBUG : left node not printing


/*
    for(int i=0;i<sz;i++){
        if(dynamic[i]!=-1 || dynamic[i]!=NULL){
            cout<<dynamic[i]<<" ";
        }
*/
}

//print right sub tree parent to child
void printRightTree(int rightParent){
    if(dynamic[rightParent]==-1 || dynamic[rightParent]==NULL){
        return;
    }

    cout<<dynamic[rightParent]<<" ";
    printRightTree((2*rightParent)+2);
    printRightTree((2*rightParent)+1);
}

//print left sub tree parent to child
void printLeftTree(int leftParent){
    if(dynamic[leftParent]==-1 || dynamic[leftParent]==NULL){
        return;
    }

    cout<<dynamic[leftParent]<<" ";
    printLeftTree((2*leftParent)+1);
    printLeftTree((2*leftParent)+2);
}



//insert into dynamic array
void insertNode(int item,int pos){

    if(sz>=capacity){
        //resize array
        capacity=2*capacity;
        int *arr=new int[capacity];
        //shift data
        for(int i=0;i<=sz;i++){
            arr[i]=dynamic[i];
        }
        delete dynamic;
        dynamic=NULL;
        dynamic=arr;
    }

    dynamic[pos]=item;
    sz++;
}

