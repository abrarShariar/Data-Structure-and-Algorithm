#include<iostream>
using namespace std;

int main(){
    int arr[4][5]={
        {1,2,3,4,5},
        {4,5,6,7,8},
        {1,0,1,2,1},
        {0,1,3,4,5}
    };

    int newArr[5][4];
    //transpose
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            newArr[j][i]=arr[i][j];
        }
    }

    //output
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            cout<<newArr[i][j]<<" ";
        }
        cout<<endl;
    }

}
