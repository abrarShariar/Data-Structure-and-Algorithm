/*
 Create an array based stack with ten integers in ascending order.
Print the data in descending order.
*/

#include<iostream>
using namespace std;
#define LIMIT 10

void push(int* stck,int* top,int item);
int pop(int* stck,int* top);

int main(){
    int myStack[LIMIT];
    int top=0;
    cout<<"Input 10 integers in ASC: "<<endl;
    for(int i=0;i<10;i++){
        int data;
        cin>>data;
        push(myStack,&top,data);
    }

    cout<<"DESC: "<<endl;
    while(top!=0){
        cout<<pop(myStack,&top)<<endl;
    }
}

void push(int* stck,int* top,int item){
    if(*top>=LIMIT){
        cout<<"\nSTACK FULL"<<endl;
        return;
    }
    stck[*top]=item;
    *top=*top+1;
}

int pop(int* stck,int* top){
    int item=stck[*top-1];
    *top=*top-1;
    return item;
}
