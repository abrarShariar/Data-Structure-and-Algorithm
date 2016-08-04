/*
    Take a min heap as input and extract N items then print the min heap
    maintain heap property after extraction

    - EXTRACT MIN
*/

#include<iostream>
#include<fstream>
using namespace std;


#define LIMIT 10
int heap[LIMIT];
int extractItem();

int main(){
    int lastIndex,item;
    //take MIN HEAP as an input
    cin>>N; //heap size
    for(int i=0;i<N;i++){
        //cout<<"Item["<<i<<"]: ";
        cin<<item;
        heap[i]=item;
        lastIndex=i;
    }

    //cout<<"How many items to extract: ";
    cin>>N;
    if(N>lastIndex){
        cout<<"INVALID"<<endl;
    }else{
        for(int i=0;i<N;i++){
            cout<<extractItem()<<" ";
        }
    }
}

int extractItem(){
    //add error handling here
    if(sizeof(heap/heap[0])<=0){
        cout<<"ERROR: EMPTY HEAP"<<endl;
    }else{
        int item=heap[0];
        //heapify down to maintain heap property

    }
}
