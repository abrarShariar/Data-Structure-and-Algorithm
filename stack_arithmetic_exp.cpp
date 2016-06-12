/*
    checking arithmetic expression validity using stack
*/
#include<iostream>
#include<conio.h>
using namespace std;
#define LIMIT 20

void push(char *stck,int *top,char value);
void showStack(char *stck,int *top);
char pop(char *stck,int *top);

int main(){

    char myStack[LIMIT];
    int top=0;
    char popItem;
    bool isValid=true;
    //take input
    while(isValid){
        char item;
        item=getche();
        if(item=='X'){
            break;
        }
        if(item=='(' || item=='{' || item=='['){
            push(myStack,&top,item);
        }
        if(item==')' && pop(myStack,&top)!='(' ){
            isValid=false;
            break;
        }
        if(item=='}' && pop(myStack,&top)!='{'){
            isValid=false;
            break;
        }
        if(item==']' && pop(myStack,&top)!='['){
            isValid=false;
            break;
        }
    }

    if(!isValid){
        cout<<"\nINVALID EXPRESSION"<<endl;
    }

    //showStack(myStack,&top);

}
char pop(char *stck,int *top){
    *top=*top-1;
    return stck[*top];
}

void push(char *stck,int *top,char value){
    if(*top==LIMIT){
        cout<<"STACK FULL"<<endl;
        return;
    }
    stck[*top]=value;
    *top=*top+1;
}

void showStack(char *stck,int *top){
    for(int i=*top-1;i>=0;i--){
        cout<<stck[i]<<" ";
    }
}
