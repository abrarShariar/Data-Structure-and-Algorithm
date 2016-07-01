/*
    hourglass problem
*/

#include<iostream>
using namespace std;

int getSum(int*);
int main(){

/*
    int arr[6][6]={
        {1,1,1,0,0,0},
        {0,1,0,0,0,0},
        {1,1,1,0,0,0},
        {0,0,2,4,4,0},
        {0,0,0,2,0,0},
        {0,0,1,2,4,0}
    };
*/
    int arr[6][6];
    //take input
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cin>>arr[i][j];
        }
    }


    int maxSum=getSum(&arr[0][0]);
    //getSum(&arr[3][2]);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int sum=getSum(&arr[i][j]);
            if(sum>maxSum){
                maxSum=sum;
            }
        }
    }
    cout<<maxSum<<endl;
}

int getSum(int *parr){
    int sum=0;
    //first 3 elements
    for(int i=0;i<3;i++){
        sum+=*(parr+i);
    }
    //middle element
    sum+=*(parr+7);

    //last three elements
    for(int i=12;i<15;i++){
        sum+=*(parr+i);
    }
    return sum;
}
