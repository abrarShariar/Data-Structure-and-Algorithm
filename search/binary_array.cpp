/*
    binary search of a sorted (ASC) array
    O(log N)
*/

#include<iostream>
using namespace std;

int binarySearch(int*,int);
bool isFound;

int main(){
    int arr[]={10,11,12,13,14,15};
    int in;
    cin>>in;
    cout<<binarySearch(arr,in)<<endl;
}

int binarySearch(int *parr,int in){
    int sz=sizeof(parr)/sizeof(parr[0]);
    int mid;

     if(in>parr[sz-1] || in<parr[0]){       //ERROR condition NOT FOUND
        cout<<"NOT FOUND"<<endl;
        return -1;
    }
    //find median
    if(sz%2==0){
        mid=sz/2;
    }else{
        mid=(sz+1)/2;
    }

    //binary search starts
    if(in==parr[mid-1]){
        cout<<"FOUND: ";
        return in;
    }
    else if(in>parr[mid-1]){
        //split left -> go right
        binarySearch(&parr[mid],in);        //recursion
    }else{
        //spit right -> go left
        binarySearch(parr,in);              //recursion
    }
}
