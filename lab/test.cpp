#include<iostream>
using namespace std;


int main(){
    int *arr=new int[10];
    //arr=NULL;
    for(int i=0;i<10;i++){
        arr[i]=-1;
    }
    arr[1]=20;
    arr[3]=40;
    for(int i=0;i<10;i++){
        cout<<arr[i]<<endl;
    }



}
