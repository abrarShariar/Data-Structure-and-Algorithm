//SOLVED
/*
https://www.hackerrank.com/challenges/dynamic-array?h_r=next-challenge&h_v=zen

*/


#include<iostream>
using namespace std;

int capacity,lastAns=0;

struct seq{
    int sz;
    int capacity=2;
    int* pseq;
};

void push(seq*,int);

int main(){
    int N,Q;            //number of sequence

    cin>>N>>Q;

    seq* seqList[N];    //define two seq
    seq *nptr,*tptr;

    //initialize sequence list
    for(int i=0;i<N;i++){
        nptr=new seq;
        nptr->sz=0;
        int* arr=new int[nptr->capacity];
        nptr->pseq=arr;
        seqList[i]=nptr;
    }

    //take input query
    for(int i=0;i<Q;i++){
        int query,x,y,index;
        cin>>query>>x>>y;
        index=((x^lastAns)%N);
        tptr=seqList[index];

        if(query==1){
            push(tptr,y);
        }else{
            int i=y%tptr->sz;
            lastAns=tptr->pseq[i];
            cout<<lastAns<<endl;
        }
    }


    /*
    push(seqList[1],30);
    push(seqList[1],40);

    seq* temp;
    temp=seqList[1];
    for(int i=0;i<temp->sz;i++){
    */
}

void push(seq* mySeq,int item){
    //if array full
    if(mySeq->sz==mySeq->capacity){
        mySeq->capacity=mySeq->capacity*2;
        int* arr=new int[mySeq->capacity];
        for(int i=0;i<mySeq->sz;i++){
            arr[i]=mySeq->pseq[i];
        }
        delete mySeq->pseq;
        mySeq->pseq=arr;
    }

    mySeq->pseq[mySeq->sz]=item;
    mySeq->sz=mySeq->sz+1;
}
