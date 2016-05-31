#include<iostream>
using namespace std;

int main(){
    int arr[10];
    int maxNum=0,minNum=0;
    //input
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }
    //calculate
    maxNum=arr[0];
    minNum=arr[0];
    for(int i=1;i<10;i++){
        if(arr[i]>maxNum){
            maxNum=arr[i];
        }
        if(arr[i]<minNum){
            minNum=arr[i];
        }
    }

    //output
    cout<<"MAX: "<<maxNum<<endl;
    cout<<"MIN: "<<minNum<<endl;
}
