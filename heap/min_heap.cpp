/*
    MIN Heap implemented
    - CREATE
    - INSERT
*/

#include<iostream>
using namespace std;

#define LIMIT 10
int minHeap[LIMIT];
void printMinHeap(int);
void insertItem(int,int);

int main(){
    int item;
    int lastIndex;
    for(int i=0;i<5;i++){
        //cout<<"Item["<<i<<"]: ";
        cin>>item;
        insertItem(i,item);
        lastIndex=i;
    }
    //printMinHeap();

    //take input for insertion in a min heap already created
    //cout<<"How many items you want to insert: ";
    int totalInsert;
    cin>>totalInsert;
    for(int i=0;i<totalInsert;i++){
        cout<<""
        cin>>item;
        insertItem(lastIndex+1,item);
        lastIndex++;
    }
    printMinHeap(lastIndex);

}


void printMinHeap(int lastIndex){
    for(int i=0;i<=lastIndex;i++){
        cout<<minHeap[i]<<endl;
    }
}

//insert into min heap and heapify up (if necessary)
void insertItem(int root,int item){
    if(root<=0){
        minHeap[root]=item;
        return;
    }

    int parent=(root-1)/2;
    if(item<minHeap[parent]){
        //swap parent
        minHeap[root]=minHeap[parent];
        //recursive call
        insertItem(parent,item);
    }else{
        minHeap[root]=item;
        return;
    }
}

