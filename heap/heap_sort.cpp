/*
    Heap sort implemented
*/


#include<iostream>
using namespace std;

void heap_sort(int*,int,int);

int main(){
    int limit,item;
    cout<<"Max Size: ";
    cin>>limit;

    int dataArray[limit];
    //take input and store in array
    for(int i=0;i<limit;i++){
        cout<<"Item["<<i<<"]: ";
        cin>>item;
        dataArray[i]=item;
    }

    //take each item and store in max heap way
    int* heap=new int[limit];
    for(int i=0;i<limit;i++){
        heap_sort(heap,dataArray[i],i);
    }

    //test print max heap
    for(int i=0;i<limit;i++){
        cout<<heap[i]<<endl;
    }
}

void heap_sort(int* heap,int item,int index){
    if(index<0){
        return;
    }

    if(index==0){
        heap[index]=item;
        return;
    }

    int parent=(index-1);
    if(item<heap[parent]){
        heap[index]=item;
        return;
    }

    //heapify up
    heap[index]=heap[parent];
    heap_sort(heap,item,parent);
}
