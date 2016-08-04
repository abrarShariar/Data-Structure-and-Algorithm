//ASC array to DESC
#include<iostream>
using namespace std;

int main(){
    int arr[]={11,21,100,999};
    int len=sizeof(arr)/sizeof(arr[0]);
    cout<<"ASC: "<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }

    //reverse sort (ASC to DESC)
    int j=len-1;
    int i=0;
    while(i<=j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }

    //print
    cout<<"\nDESC: "<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
}

