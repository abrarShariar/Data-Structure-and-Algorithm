#include<iostream>
#include<conio.h>
using namespace std;
#define LIMIT 20

void push(int*,int*,int);
int pop(int*,int*);

int main(){
    int myStack[LIMIT];
    int top=0;
    char ch;
    bool isValid=true;

    cout<<"INPUT: "<<endl;
    while((ch=getche())!='$'){
        if(top>=LIMIT){
            break;
        }
        if(ch=='(' || ch=='{' || ch=='['){
            push(myStack,&top,ch);
        }
        else if(ch==')' && pop(myStack,&top)!='('){
            isValid=false;
            break;
        }
        else if(ch=='}' && pop(myStack,&top)!='{'){
             isValid=false;
             break;
        }
        else if(ch==']' && pop(myStack,&top)!='['){
            isValid=false;
            break;
        }
    }

    if(isValid){
        cout<<"\nValid Expression"<<endl;
    }else{
        cout<<"\nInvalid Expression"<<endl;
    }
}

int pop(int* stck,int* top){
    if(*top<0){
        cout<<"STACK EMPTY"<<endl;
        return *top;
    }
    *top=*top-1;
    return stck[*top];
}

void push(int* stck,int* top,int item){
    if(*top>=LIMIT){
        cout<<"\nSTACK FULL"<<endl;
        return;
    }
    stck[*top]=item;
    *top=*top+1;
}
