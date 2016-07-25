//complete binary tree implemented using dynamic array

#include<iostream>
using namespace std;
#define LIMIT 10    //max nodes

int capacity=10;      //size of initial array
int sz=0;
int *dynamic;   //pointer to dynamic array
int countNode=0;

void insertNode(int,int);
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
    while(countNode<=LIMIT){
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

    for(int i=0;i<sz;i++){
        if(dynamic[i]!=-1 || dynamic[i]!=NULL){
            cout<<dynamic[i]<<" ";
        }
    }


}


//insert into dynamic array
void insertNode(int item,int pos){

    if(sz>=capacity){
        //resize array
        capacity=2*capacity;
        int *arr=new int[capacity];
        //shift data
        for(int i=0;i<sz;i++){
            arr[i]=dynamic[i];
        }
        delete dynamic;
        dynamic=NULL;
        dynamic=arr;
    }

    dynamic[pos]=item;
    sz++;
}
