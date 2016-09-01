/*
    INSERTION SORT
    - iterative
    - recuresive
*/
#include<iostream>
using namespace std;

void insertSort(int*,int,int);

int main(){

	int arr[]={5,2,4,6,1,3};
	int sz=sizeof(arr)/sizeof(arr[0]);

	//insertion sort - interative way
	for(int k=1;k<sz;k++){
		int item=arr[k];
		int i=k;
		while(item < arr[i-1] && i>0){
			//pairwise swap
			arr[i]=arr[i-1];
			arr[i-1]=item;
			i--;
		}
	}
	//test print sorted array
	for(int i=0;i<sz;i++){
		cout<<arr[i]<<" ";
	}
    cout<<endl;

	//trying insertion sort in recursive way
	int nArr[]={50,20,40,60,10,30};
	sz=sizeof(nArr)/sizeof(nArr[0]);

    for(int k=1;k<sz;k++){
        insertSort(nArr,k,sz);
    }
	//test print
    for(int i=0;i<sz;i++){
        cout<<nArr[i]<<" ";
    }
}

void insertSort(int* parr,int key,int sz){

        if(key<=0){
            return;
        }

        if(parr[key] >= parr[key-1]){
            return;
        }

        //pairwise swap
        int item=parr[key];
        parr[key]=parr[key-1];
        parr[key-1]=item;

        insertSort(parr,key-1,sz);
}







