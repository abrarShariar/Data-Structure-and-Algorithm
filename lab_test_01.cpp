#include<iostream>
using namespace std;
#define LIMIT 10

int main(){
    int arr[LIMIT];
    double sum=0,avg;

    cout<<"INPUT: "<<endl;
    for(int i=0;i<LIMIT;i++){
        cin>>arr[i];
    }

    //calculation
    for(int i=0;i<LIMIT;i++){
        sum+=arr[i];
    }
    avg=sum/LIMIT;

    //output
    cout<<"OUTPUT: ";
    for(int i=0;i<LIMIT;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nSUM: "<<sum<<endl;
    cout<<"AVERAGE: "<<avg<<endl;
}


/*
int main(){
    int X=100,Y=999;
    cout<<X<<" "<<Y<<endl;
    int *px,*py;
    px=&X;
    py=&Y;
    *px=0;
    *py=0;

    cout<<X<<" "<<Y<<endl;
    px=py;
    *px=666;

    cout<<X<<" "<<Y<<endl;
    py=&X;
    cout<<X<<" "<<Y<<endl;
    *px=10;
    *py=20;
    cout<<X<<" "<<Y<<endl;
}
*/
