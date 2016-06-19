/*
    queue implemented with array
*/

#include<iostream>
using namespace std;
#define LIMIT 10

void insertItem(int* que,int* qRear,int item);
int getItem(int* que,int* qFront);

int main(){
    int qFront=0,qRear=0;
    int que[LIMIT];
    int input;
    cout<<"INPUT:"<<endl;
    for(int i=0;i<LIMIT;i++){
        cin>>input;
        insertItem(que,&qRear,input);
    }

    cout<<"\nOUTPUT:"<<endl;
    for(int i=qFront;i<qRear;i++){
        cout<<getItem(que,&qFront)<<" ";
    }

}

int getItem(int* que,int* qFront){
    if(*qFront>=LIMIT){
        cout<<"NO ITEM IN QUEUE"<<endl;
        return NULL;
    }
    int item=que[*qFront];
    *qFront=*qFront+1;
    return item;
}

void insertItem(int* que,int* qRear,int item){
    if(*qRear>=LIMIT){
        cout<<"QUEUE FULL"<<endl;
        return;
    }
    que[*qRear]=item;
    *qRear=*qRear+1;
}
