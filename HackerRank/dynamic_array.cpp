#include<iostream>
using namespace std;

int capacity;
//int sz=0;
int lastAns=0;

struct seq{
    int sz;
    int* pseq;
};

void push(seq*,int);

int main(){
    int N;            //number of sequence
    int capacity;     //number of query

    cin>>N>>capacity;

    seq* seqList[N];    //define two seq
    seq *nptr,*tptr;

    //initialize sequence list
    for(int i=0;i<N;i++){
        nptr=new seq;
        nptr->sz=0;
        int* arr=new int[capacity];
        nptr->pseq=arr;
        seqList[i]=nptr;
    }

    //take input query
    for(int i=0;i<capacity;i++){
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
    mySeq->pseq[mySeq->sz]=item;
    mySeq->sz=mySeq->sz+1;
}
