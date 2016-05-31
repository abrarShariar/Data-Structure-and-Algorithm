#include<iostream>
using namespace std;

int main(){
    int arr[10];
    double sum=0,avg;
    //input
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }
    //calculate
    for(int i=0;i<10;i++){
        sum+=arr[i];
    }
    avg=sum/10;
    //output
    for(int i=0;i<10;i++){
       cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"SUM: "<<sum<<endl;
    cout<<"AVG: "<<avg<<endl;
}
