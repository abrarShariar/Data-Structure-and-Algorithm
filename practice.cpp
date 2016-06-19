#include<iostream>
#include<conio.h>
using namespace std;
#define LIMIT 20

void push(int* myStack,int* top,int item);
int pop(int* myStack,int* top);

int main(){

    int myStack[LIMIT];
    int top=0;
    char input;
    bool isValid=true;

    cout<<"INPUT: "<<endl;
    while(true){
        input=getche();
        if(top>=LIMIT){
            break;
        }
        if(input=='(' || input=='{' || input=='['){
            push(myStack,&top,input);
        }
        else if(input==')' && pop(myStack,&top)!='('){
            isValid=false;
            break;
        }
        else if(input=='}' && pop(myStack,&top)!='{'){
            isValid=false;
            break;
        }
        else if(input==']' && pop(myStack,&top)!='['){
            isValid=false;
            break;
        }
    }
    if(isValid){
        cout<<"\nValid Expression"<<endl;
    }else{
        cout<<"\nInValid Expression"<<endl;
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
    if(*top<=0){
        cout<<"\nSTACK EMPTY"<<endl;
        return -1;
    }
    int data=stck[*top-1];
    *top=*top-1;
    return data;
}
