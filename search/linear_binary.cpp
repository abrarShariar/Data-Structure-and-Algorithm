/*
    linear and binary search (used clock)
*/
#include<iostream>
#include<cstdio>
#include<time.h>
using namespace std;

template<typename Type>void linearSearch(Type*,Type,int);
template<typename Type>bool binarySearch(Type*,Type,int);

int main(){
    clock_t t;

    //go linear
    //change data and arr[] to other data types as necessary
    int data;
    int arr[]={20,30,10,1,60,70,80,10};

    int sz=(sizeof(arr)/sizeof(arr[0]));
    cout<<"Search [linear]: ";
    cin>>data;
    t=clock();
    linearSearch<int>(arr,data,sz);
    t=clock()-t;
    //cout<<"Linear search done in "<<t<<" clicks. "<<((float)t)/CLOCKS_PER_SEC;
    printf("Linear search done in %d clicks. ( %f seconds )",t,((double)t)/CLOCKS_PER_SEC);
    //go binary
    int bArr[]={10,20,30,40,50,60,70,80};
    sz=sizeof(bArr)/sizeof(bArr[0]);
    cout<<"\nSearch [binary]: ";
    cin>>data;
    t=clock();
    binarySearch<int>(bArr,data,sz);
    t=clock()-t;
    printf("Binary search done in %d clicks ( %f seconds )",t,((double)t)/CLOCKS_PER_SEC);
}

//binary search (template function)
template<typename Type>bool binarySearch(Type* parr,Type item,int sz){

    if(parr[0]!=item && sz<=0){
        cout<<"Not Found"<<endl;
        return false;
    }

    if(parr[0]==item || parr[sz/2]==item){
        cout<<"Found Item: "<<item<<endl;
        return true;
    }

    else if(item>parr[sz/2]){
        //go right
        binarySearch((parr+(sz/2)),item,sz/2);
    }
    else if(item<parr[sz/2]){
        //go left
        binarySearch(parr,item,sz/2);
    }
}
//linear search (template function)
template<typename Type>void linearSearch(Type* parr,Type item,int sz){
    bool isFound=false;
    int pos;
    for(int i=0;i<sz;i++){
        if(parr[i]==item){
            isFound=true;
            pos=i;
            break;
        }
    }
    if(isFound){
        cout<<"Found Item: "<<item<<" at position "<<pos<<endl;
    }else{
        cout<<"Not Found Item"<<endl;
    }
}
