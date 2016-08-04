
//binary tree implemented using dynamic array
/*
    - PRE-ORDER
    - IN-ORDER
    - POST-ORDER
*/
#include<iostream>
using namespace std;
//binary tree with 11 nodes
#define LIMIT 11    //max nodes

int capacity=5;      //size of initial array
int sz=0;
int *dynamic;   //pointer to dynamic array
int countNode=0;

void insertNode(int,int);
void printPreorder(int);
void printInorder(int);
void printPostorder(int);

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
        if(dynamic[root]!=-1 || dynamic[root]!=NULL){
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
        }
            root++;
    }

    //print tree in preorder
    cout<<"\n\nPREORDER : "<<endl;
    printPreorder(0);

    cout<<"\n\nINORDER : "<<endl;
    printInorder(0);

    cout<<"\n\nPOSTORDER : "<<endl;
    printPostorder(0);

    cout<<endl;
}

//traverse postorder
void printPostorder(int root){
    if(dynamic[root]==-1 || dynamic[root]==NULL){
        return;
    }

    printPostorder((2*root)+1);
    printPostorder((2*root)+2);
    cout<<dynamic[root]<<" ";
}

//traverse inorder
void printInorder(int root){
    if(dynamic[root]==-1 || dynamic[root]==NULL){
        return;
    }

    printInorder((2*root)+1);
    cout<<dynamic[root]<<" ";
    printInorder((2*root)+2);
}

//traverse preorder
void printPreorder(int root){
    if(dynamic[root]==-1 || dynamic[root]==NULL){
        return;
    }

    cout<<dynamic[root]<<" ";
    printPreorder((2*root)+1);
    printPreorder((2*root)+2);
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
        //dynamic=NULL;
        dynamic=arr;
    }

    dynamic[pos]=item;
    sz++;
}
