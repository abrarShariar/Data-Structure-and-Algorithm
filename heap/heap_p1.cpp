#include<iostream>
using namespace std;

void insertMaxHeap(int*,int,int);

int main(){
    int limit,item;
    cout<<"Max Size: ";
    cin>>limit;

    int heap[limit];
    //take input and store in array
    for(int i=0;i<limit;i++){
        cout<<"Item["<<i<<"]: ";
        cin>>item;
        heap[i]=item;
    }

    //take each item and store in max heap way
    int* max_heap=new int[limit];
    for(int i=0;i<limit;i++){
        insertMaxHeap(max_heap,heap[i],i);
    }

    //test print max heap
    for(int i=0;i<limit;i++){
        cout<<max_heap[i]<<endl;
    }
}

void insertMaxHeap(int* max_heap,int item,int index){
    if(index<0){
        return;
    }

    if(index==0){
        max_heap[index]=item;
        return;
    }

    int parent=(index-1);
    if(item<max_heap[parent]){
        max_heap[index]=item;
        return;
    }

    //heapify up
    max_heap[index]=max_heap[parent];
    insertMaxHeap(max_heap,item,parent);
}
