//reverse output using stack (array based)
#include<iostream>
#include<cstdio>
using namespace std;
#define LIMIT 30

void push(char* stck,int* top,char item);
char pop(char* stck,int* top);

int main(){
    char myStack[LIMIT];
    int top=0;

    cout<<"INPUT: ";

    while(true){
        char input;
        input=getchar();
        if(input=='$'){
            break;
        }
        push(myStack,&top,input);
    }

    cout<<"\nOUTPUT: ";
    while(top>0){
        cout<<pop(myStack,&top);
    }
}

void push(char* stck,int* top,char item){
    if(*top>=LIMIT){
        cout<<"\nSTACK FULL"<<endl;
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

