#include<iostream>
using namespace std;

double findAvg(int *parr);

int main(){
    int arr[5][4]={
        {20,10,13,10},
        {10,20,16,20},
        {10,22,23,29},
        {10,20,30,10},
        {10,23,23,19}
    };


    for(int i=0;i<5;i++){
        double bestAvg=findAvg(&arr[i][0]);
        cout<<"Student["<<i<<"]: "<<bestAvg<<endl;
    }
}

double findAvg(int *parr){

   double sum=0,avg=0;
    //sort in DESC
    bool isSort=false;
    while(!isSort){
        isSort=true;
        for(int i=1;i<4;i++){
            if(parr[i]>parr[i-1]){
                isSort=false;
                int temp=parr[i];
                parr[i]=parr[i-1];
                parr[i-1]=temp;
            }
        }
    }

    //average of best 3
    for(int i=0;i<3;i++){
        sum+=parr[i];
    }
    avg=sum/3;

    return avg;

    //cout<<avg<<endl;
    //test output
    /*
    for(int i=0;i<4;i++){
        cout<<parr[i]<<endl;
    }
    */
}
