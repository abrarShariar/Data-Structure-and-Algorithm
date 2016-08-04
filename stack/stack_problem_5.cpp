/*
    arithmetic expression validity check
*/
#include<iostream>
#include<conio.h>
using namespace std;
#define LIMIT 20

void push(char* stck,int* top,int item);
char pop(char* stck,int* top);

int main(){
    char myStack[LIMIT];
    int top=0;
    bool isValid=true;
    cout<<"INPUT: ";

    while(isValid){
        char input;
        input=getche();
        if(input=='$'){
            break;
        }
        if(input=='[' || input=='{' || input=='('){
            push(myStack,&top,input);
        }
        if(input==']' && pop(myStack,&top)!='['){
            cout<<"\nINVALID"<<endl;
            isValid=false;
            break;
        }
        if(input=='}' && pop(myStack,&top)!='{'){
            cout<<"\nINVALID"<<endl;
            isValid=false;
            break;
        }
        if(input==')' && pop(myStack,&top)!='('){
            cout<<"\nINVALID"<<endl;
            isValid=false;
            break;
        }
    }

    if(isValid){
        cout<<"\nVALID EXPRESSION"<<endl;
    }
}

void push(char* stck,int* top,int item){
    if(*top>=LIMIT){
        cout<<"\tSTACK FULL"<<endl;
        return;
    }
    stck[*top]=item;
    *top=*top+1;
}

char pop(char* stck,int* top){
    char item=stck[*top-1];
    *top=*top-1;
    return item;
}
