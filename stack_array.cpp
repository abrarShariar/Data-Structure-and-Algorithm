#include<iostream>
using namespace std;

#define LIMIT 10

int push(int* stck,int* top,int value);
int pop(int* stck,int* top);
void showStack(int* stck,int* top);

int main(){
    int myStack[LIMIT];
    int top=0,item=0;


    while(true){
        cout<<"PUSH DATA: ";
        cin>>item;
        if(push(myStack,&top,item)==0){
            cout<<"STACK FULL"<<endl;
            break;
        }
    }

    //before pop
    cout<<"\nSHOW STACK :"<<endl;
    showStack(myStack,&top);

    cout<<"\nPOP DATA: "<<endl;
    cout<<pop(myStack,&top)<<endl;
    cout<<pop(myStack,&top)<<endl;
    cout<<pop(myStack,&top)<<endl;

    //after pop
    cout<<"\nSHOW STACK :"<<endl;
    showStack(myStack,&top);
}

int pop(int* stck,int* top){
    if(*top==0){
        cout<<"STACK EMPTY"<<endl;
        return 0;
    }
    *top=*top-1;
    int item=stck[*top];
    return item;
}

int push(int* stck,int* top,int value){
    if(*top==LIMIT){
        return 0;
    }
    stck[*top]=value;
    *top=*top+1;
    return *top;
}

void showStack(int* stck,int* top){
     for(int i=*top-1;i>=0;i--){
        cout<<stck[i]<<" "<<endl;
     }
}
