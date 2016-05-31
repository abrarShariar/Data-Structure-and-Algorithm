#include<iostream>
using namespace std;

int main(){
    int arr[5]={10,11,12,13};
    int pos=2,num=1000;

    //insert at pos
    for(int i=4;i>pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=num;
    //output
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}
