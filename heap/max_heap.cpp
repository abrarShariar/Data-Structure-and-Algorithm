/*
    MAX HEAP implemented in C++
    - INSERT
    - Extract Max

*/
#include<iostream>
using namespace std;

void insertHeapItem(int*,int,int);
int extractMax(int*,int*);
void printMaxHeap(int*,int);

int main(){
    int N,item,ext;
    //cout<<"Total Items: "
    cin>>N;
    int maxHeap[N];
    for(int i=0;i<N;i++){
        cin>>item;
        insertHeapItem(maxHeap,item,i);
    }

    //print max heap before extraction
    printMaxHeap(maxHeap,N);
    //cout<<"How many items to extract: ";
    cin>>ext;
    for(int i=0;i<ext;i++){
        cout<<extractMax(maxHeap,&N)<<" ";
        //extractMax(maxHeap,&N);
    }

    //print to std output
    //printMaxHeap(maxHeap,N);
}

int extractMax(int *heap,int *lastIndex){
    //get max element from root
    int root=0;
    int extract=heap[root];
    int lastElement=heap[(*lastIndex-1)];
    //heapify down
    bool isHeapified=false;
    while(!isHeapified){
        //compare lchild and rchild -> get max
        if(heap[(2*root+1)] > heap[(2*root+2)]){
            heap[root]=heap[(2*root+1)];
            root=2*root+1;
        }else{
            heap[root]=heap[(2*root+2)];
            root=2*root+2;
        }

        //check if root is the end of heap
        if((2*root+1)>=*lastIndex && (2*root+2)>=*lastIndex){
            heap[root]=lastElement;
            isHeapified=true;
        }
        else if((2*root+1) < *(lastIndex) && (2*root+2)>=*lastIndex){
            heap[(2*root+1)]=lastElement;
            isHeapified=true;
    }
    *lastIndex=*lastIndex-1;
 }

    return extract;
}

void printMaxHeap(int* heap,int sz){
    for(int i=0;i<sz;i++){
        cout<<heap[i]<<endl;
    }
}

void insertHeapItem(int* heap,int item,int index){
    if(index==0){
        heap[index]=item;
        return;
    }

    int parent=(index-1)/2;
    if(heap[parent] >= item){
        heap[index]=item;
        return;
    }

    //heapify up
    heap[index]=heap[parent];
    insertHeapItem(heap,item,parent);
}
