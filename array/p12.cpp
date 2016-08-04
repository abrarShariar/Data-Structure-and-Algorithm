#include<iostream>
using namespace std;

int main(){
    int arr[4][4]={
        {1,2,3,10},
        {4,5,6,11},
        {1,0,1,20},
        {2,3,4,5}
    };

    //transpose
    for(int i=0;i<4;i++){
        for(int j=i;j<4;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }

    //output
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
