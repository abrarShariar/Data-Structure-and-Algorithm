#include<iostream>
using namespace std;


void MergeSort(int*,int,int);
void Merge(int*,int,int,int);

int main(){

    int arr[]={5,4,3,1};
    int sz=sizeof(arr)/sizeof(arr[0]);
    int p=0,r=sz-1;

    MergeSort(arr,p,r);

    //print sorted array
    for(int i=0;i<sz;i++){
        cout<<arr[i]<<" ";
    }
}

void MergeSort(int* arr,int p,int r){

    if(p<r){
        //continue to divide and conquer
        int q=(r+p)/2;
        MergeSort(arr,p,q);
        MergeSort(arr,q+1,r);
        Merge(arr,p,q,r);
    }
}

void Merge(int* parr,int p,int q,int r){

    int lSize=(q-p)+1;
    int rSize=(r-q);

    int* lArr=new int[lSize];
    int* rArr=new int[rSize];

    //copy elements to left and right array
    for(int i=0;i<lSize;i++){
        lArr[i]=parr[p+i];
    }
    for(int i=0;i<rSize;i++){
        rArr[i]=parr[q+1+i];
    }

    //sort and merge
    int l=0,j=0,k=p;
    while(l<lSize && j<rSize){
        if(lArr[l] < rArr[j]){
            parr[k]=lArr[l];
            l++;
        }else{
            parr[k]=rArr[j];
            j++;
        }
        k++;
    }

    //deal with left-overs
    while(l<lSize){
        parr[k]=lArr[l];
        l++;
        k++;
    }
    while(j<rSize){
        parr[k]=rArr[j];
        j++;
        k++;
    }
}
