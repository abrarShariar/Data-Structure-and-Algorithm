#include<iostream>
using namespace std;

int main(){
    int arr[10];
    int evenSum=0,oddSum=0;
    //input
    for(int i=0;i<10;i++){
        cin>>arr[i];
        if(arr[i]%2==0){
            evenSum+=arr[i];
        }else{
            oddSum+=arr[i];
        }
    }

    //output
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"EVEN SUM: "<<evenSum<<endl;
    cout<<"ODD SUM: "<<oddSum<<endl;
}
