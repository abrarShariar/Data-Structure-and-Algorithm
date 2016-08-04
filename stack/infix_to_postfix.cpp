/*
    infix to postfix conversion
*/
#include<iostream>
using namespace std;
#define LIMIT 20

void push(char* stck,int* top,char item);
char pop(char* stck,int* top);

int main(){
    char myStack[LIMIT];
    //char postfix[LIMIT];
    int top=0;
    int postIndex=0;
    char postfix[LIMIT];

    cout<<"INPUT: "<<endl;

    while(true){
        char input;
        cin>>input;
        if(input=='$'){
            break;
        }
        else if(input=='[' || input=='{' || input=='(' || input=='^' || input=='/' || input=='*' || input=='+' || input=='-'){
            push(myStack,&top,input);
        }
        else if(input==')' || input=='}' || input==']'){
            while(top>=0){
                char out=pop(myStack,&top);
                if(out!='(' || out!='{' || out!='['){
                    postfix[postIndex]=out;
                    postIndex++;
                }
            }
        }
        else{
            postfix[postIndex]=input;
            postIndex++;
        }
    }
    //print stack
    for(int i=0;i<postIndex;i++){
        cout<<postfix[i];
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
    char popItem=stck[*top-1];
    *top=*top-1;
    return popItem;
}

