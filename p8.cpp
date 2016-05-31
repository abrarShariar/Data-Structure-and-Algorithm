#include<iostream>
using namespace std;

int main(){
    int arr1[5]={1,3,5,7,9};
    int arr2[5]={2,4,6,8,10};
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

    //sort
    bool isSort=false;
    while(!isSort){
        isSort=true;
        for(int i=1;i<10;i++){
            if(arr3[i]<arr3[i-1]){
                isSort=false;
                int temp=arr3[i];
                arr3[i]=arr3[i-1];
                arr3[i-1]=temp;
            }
        }
    }
    //output
    for(int i=0;i<10;i++){
        cout<<arr3[i]<<endl;
    }

}
