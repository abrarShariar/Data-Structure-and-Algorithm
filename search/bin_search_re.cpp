//BINARY SEARCH USING RECURSION

#include<iostream>
using namespace std;

void binarySearch(int*,int,int);

int main(){

    int arr[]={10,20,30,40,50,60,70};
    int sz=sizeof(arr)/sizeof(arr[0]);

    //test if found / not found
    for(int i=0;i<100;i+=10){
        cout<<"Search["<<i<<"]: ";
        binarySearch(arr,sz-1,i);
    }

}

void binarySearch(int* arr,int sz,int num){
    sz=sz/2;
    if(arr[sz]==num){
        cout<<"FOUND"<<endl;
        return;
    }
    if(sz==0){
        if(arr[sz]==num){
            cout<<"FOUND"<<endl;
        }
        else{
            cout<<"NOT FOUND"<<endl;
        }
        return;
    }

    if(num > arr[sz]){
        binarySearch(&arr[sz+1],sz,num);
    }else{
        binarySearch(&arr[0],sz,num);
    }
}





