#include<iostream>
using namespace std;

int main(){
    int arr1[5]={1,2,3,4,5};
    int arr2[5]={10,11,12,13,14};
    int arr3[10];

    //merge
    int j=0;
    for(int i=0;i<10;i++){
        if(i<5){
            arr3[i]=arr1[i];
        }else{
            arr3[i]=arr2[j];
            j++;
        }
    }

    //output
    for(int i=0;i<10;i++){
        cout<<arr3[i]<<" ";
    }
}
