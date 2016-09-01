#include<iostream>
using namespace std;

void Merge(int*,int,int,int);

int main(){

    int arr[]={2,4,5,7,8,1,2,3,6,9};
    int sz=sizeof(arr)/sizeof(arr[0]);
    Merge(arr,0,(sz/2)-1,sz-1);

    //test print
    for(int i=0;i<sz;i++){
        cout<<arr[i]<<" ";
    }
}

void Merge(int *parr,int p,int q,int r){
    //int lArr[]={2,4,5,7,8};
    //int rArr[]={1,2,3,6,9};
    int n1=q-p+1;
    int n2=r-q;
    int lArr[n1];
    int rArr[n2];

//prepare left array
    for(int i=0;i<n1;i++){
        lArr[i]=parr[p+i];
    }
//prepare right array
    for(int i=0;i<n2;i++){
        rArr[i]=parr[q+1+i];
    }

    int k=0,li=0,ri=0;
    while(li<n1 && ri<n2){
        if(lArr[li]<=rArr[ri]){
            parr[k]=lArr[li];
            li++;
        }else{
            parr[k]=rArr[ri];
            ri++;
        }
        k++;
    }

    while(li<n1){
        parr[k]=lArr[li];
        li++;
        k++;
    }

    while(ri<n2){
        parr[k]=rArr[ri];
        ri++;
        k++;
    }
}
