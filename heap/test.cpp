#include<iostream>
using namespace std;

void modArray(int*);

int main(){

    int *arr=new int[5];
    for(int i=0;i<5;i++){
        arr[i]=0;
    }

    modArray(arr);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }
}

void modArray(int* arr){

    for(int i=0;i<5;i++){
        arr[i]=1;
    }
}
