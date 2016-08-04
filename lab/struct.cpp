#include<iostream>
using namespace std;

int main(){
    int arr[]={1,10,90,100};
    int del;
    //display
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nDELETE DATA: ";
    cin>>del;
    for(int i=0;i<4;i++){
        if(arr[i]==del){
            //cout<<i<<endl;
            for(int j=i+1;j<4;j++){
                arr[j-1]=arr[j];
            }
            break;
        }
    }

    //display
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";
    }
}

/*
void alterArray(int* arr,int insertData,int pos);
void displayArray(int* arr,int len);

int main(){
    int arr[5]={1,3,4,5};
    int insertAfter;
    int insertData;
    displayArray(arr,4);

    cout<<"INSERT AFTER: ";
    cin>>insertAfter;
    cout<<"INSERT DATA: ";
    cin>>insertData;

    int pos=0;
    for(int i=0;i<4;i++){
        if(arr[i]==insertAfter){
            pos=i;
            //cout<<pos<<endl;
            alterArray(arr,insertData,pos);
            break;
        }
    }
    displayArray(arr,5);
}

void displayArray(int* arr,int len){
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void alterArray(int* arr,int insertData,int pos){
    for(int i=4;i>pos+1;i--){
        arr[i]=arr[i-1];
    }
    arr[pos+1]=insertData;
}

*/
/*
int main(){

    int arr[4][4]={
        {1,2,3,4},
        {10,22,3,4},
        {11,12,34,5},
        {0,1,0,1}
    };

    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            arr[j][i]=arr[i][j]+arr[j][i];  //y=x+y
            arr[i][j]=arr[j][i]-arr[i][j];  //x=y-x
            arr[j][i]=arr[j][i]-arr[i][j];  //y-y-x
        }
    }

    //print
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
*/
/*
int main(){
    int arr[3][4]={
        {1,1,2,3},
        {0,1,2,3},
        {2,3,1,4}
    };
    int sum=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(i==0 || j==0 || i==2 || j==3){
                sum+=arr[i][j];
            }
        }
    }
    cout<<sum<<endl;
}
*/
