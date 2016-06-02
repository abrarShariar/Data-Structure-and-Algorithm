#include<iostream>
using namespace std;


struct person{
    int id;
    string name;
};

int main(){
    person pArr[3]={
        {101,"Hello"},
        {102,"Abrar"},
        {103,"Bill"}
    };

    for(int i=0;i<3;i++){
        cout<<pArr[i].id<<" : "<<pArr[i].name<<endl;
    }
}

/*
int main(){
    person perArr[5];
    string nameArr[]={"Abrar","Bill","Steve","Jasd","Hell"};
    for(int i=0;i<5;i++){
        person p1;
        p1.id=i+100;
        p1.name=nameArr[i];
        perArr[i]=p1;
    }

    //print
    for(int i=0;i<5;i++){
        cout<<"id: "<<perArr[i].id<<" : ";
        cout<<perArr[i].name<<endl;
    }
}
*/


/*
#define ROW 3
#define COL 4

void printNumber(int *parr);

int main(){
    int arr[ROW][COL]={
        {1,2,2,3},
        {3,4,4,5},
        {4,5,1,2}
    };

    for(int i=0;i<ROW;i++){
        printNumber(&arr[i][0]);
    }
}


void printNumber(int *parr){
    for(int i=0;i<COL;i++){
        if(*(parr+i)%2==0){
            cout<<"even"<<" ";
        }else{
            cout<<"odd"<<" ";
        }
    }
    cout<<endl;
}
*/
