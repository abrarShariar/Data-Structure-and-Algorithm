/*
    dynamic array implemented in C++
*/

#include<iostream>
#include<cstdio>

using namespace std;

//pointer to dynamic array
int* parr;
int capacity=2;
int sz=0;

void push(int);
int get(int);
void setItem(int,int);

int main(){

    int* arr=new int[capacity];
    parr=arr;

    /*
    take input
    */
    cout<<"INPUT: ";
    while(true){
        int input;
        cin>>input;
        if(input==-1){
            break;
        }
        //input;
        push(input);
    }


    //test putput
    //setItem(1,200);

    cout<<"OUTPUT: ";
    for(int i=0;i<sz;i++){
        cout<<get(i)<<" ";
    }
}

void push(int num){
    //if array full
    if(sz==capacity){
        capacity=2*sz;
        int* arr=new int[capacity];
        for(int i=0;i<sz;i++){
            arr[i]=parr[i];
        }
        delete parr;
        parr=arr;
    }
    parr[sz]=num;
    sz++;
}


int get(int index){
    if(index<0 || index>=sz){
        cout<<"ERROR: Invalid Index"<<endl;
        return NULL;
    }
    return parr[index];
}

void setItem(int index,int item){
    if(index<0 || index>=sz){
        cout<<"ERROR: Invalid Index"<<endl;
        return;
    }
    parr[index]=item;
}
