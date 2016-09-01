#include<iostream>
using namespace std;

void Merge(int*,int,int,int);
void MergeSort(int*,int,int);

int main(){
    int arr[]={1,230,450,340,230,10,20,304,0};
    int sz=sizeof(arr)/sizeof(arr[0]);
//Merge(arr,0,3,7)
    //Merge(arr,0,(sz/2)-1,sz-1);
//test print
/*
    for(int i=0;i<sz;i++){
        cout<<arr[i]<<" ";
    }
*/

    MergeSort(arr,0,sz-1);
    for(int i=0;i<sz;i++){
        cout<<arr[i]<<" ";
    }
}

//MERGE SORT
void MergeSort(int* arr,int l,int r){

    if(l<r){
        int mid=(l+r)/2;
        //left
        MergeSort(arr,l,mid);
        //right
        MergeSort(arr,mid+1,r);
        //merge
        Merge(arr,l,mid,r);
    }
}

//merge subroutine
void Merge(int* parr,int l,int m,int r){
    int n1=(m-l)+1;
    int n2=r-m;

    int lArr[n1];
    int rArr[n2];
//prepare left array
    for(int i=0;i<n1;i++){
        lArr[i]=parr[l+i];
    }
//prepare right array
    for(int i=0;i<n2;i++){
        rArr[i]=parr[m+1+i];
    }
//merge temp arrays into main array
    int li=0,ri=0,ki=l;
    while(li<n1 && ri<n2){
        if(lArr[li] <= rArr[ri]){
            parr[ki]=lArr[li];
            li++;
        }else{
            parr[ki]=rArr[ri];
            ri++;
        }
        ki++;
    }

//copy remaining items
    while(li<n1){
        parr[ki]=lArr[li];
        ki++;
        li++;
    }
    while(ri<n2){
        parr[ki]=rArr[ri];
        ki++;
        ri++;
    }
}


/*
void Merge(int*,int,int,int);
void MergeSort(int*,int,int);

int main(){

    int arr[]={50,60,70,80,90,10,20,30,40};
    int sz=sizeof(arr)/sizeof(arr[0]);
    //Merge(arr,0,(sz/2)-1,sz-1);

    MergeSort(arr,0,sz);

    //test print
    for(int i=0;i<sz;i++){
        cout<<arr[i]<<" ";
    }
}

//merge-sort
void MergeSort(int *parr,int p,int r){
    if(p<r){
        int q=((p+r)/2)-1;
        //left
        MergeSort(parr,p,q);
        //right
        MergeSort(parr,q+1,r-1);
        //merge
        Merge(parr,p,q,r);
    }

}

//merge subroutine
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

//merge back to main array
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
*/
