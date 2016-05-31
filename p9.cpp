#include<iostream>
using namespace std;

int main(){
    int arr[5][5]={
        {1,2,3,4,1},
        {1,0,1,1,1},
        {1,2,3,1,1},
        {0,1,2,3,4},
        {4,0,4,1,2}
    };
    int sum=0;
    //calculate
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i==0 || i==4 || j==0 || j==4){
                sum+=arr[i][j];
            }
        }
    }

    //output
    cout<<"SUM: "<<sum<<endl;
}
