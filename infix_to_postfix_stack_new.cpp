/*
    A Lannister always pays his debts

    Algorithm
1. Scan the infix expression from left to right.
2. If the scanned character is an operand, output it.
3. Else,
…..3.1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty), push it.
…..3.2 Else, Pop the operator from the stack until the precedence of the scanned operator is less-equal to the precedence of the operator residing on the top of the stack. Push the scanned operator to the stack.
4. If the scanned character is an ‘(‘, push it to the stack.
5. If the scanned character is an ‘)’, pop and output from the stack until an ‘(‘ is encountered.
6. Repeat steps 2-6 until infix expression is scanned.
7. Pop and output from the stack until it is not empty.

*/

#include<iostream>
using namespace std;

struct node{
    char data;
    node* next;
};

node* top;
string postfix;

node* createNode(char);
void push(char);
char pop();
bool isEmpty();
char peek();
void foundClosingBracket(char);
int checkPrec(char in);
void foundOperator(char);

int main(){
    top=NULL;
    int N;
    cin>>N;
for(int i=0;i<N;i++){
    postfix="";
    //take input
    while(true){
        char in;
        cin>>in;
        //terminate taking input
        if(in=='$'){
            break;
        }
        //if opening bracket(PUSH)
        if(in=='(' || in=='{' || in=='['){
            push(in);
            continue;
        }
        //if closing bracket(POP)
        if(in==')' || in=='{' || in==']'){
            foundClosingBracket(in);
            continue;
        }
        //if operators (PUSH + POP)
        if(in=='+' || in=='-' || in=='*' || in=='/'){
            //----------ERROR - Segementation Fault----------
                foundOperator(in);
                continue;
            }
        postfix.push_back(in);
    }

    //if contents left in stack
    while(!isEmpty()){
        char out=pop();
        postfix.push_back(out);
        }
    cout<<postfix<<endl;
}
}

void foundOperator(char in){
    if(!isEmpty()){
        if(checkPrec(in)>checkPrec(peek())){
            push(in);
        }else{
            while(checkPrec(in)<=checkPrec(peek()) && peek()!='$'){
                char out=pop();
                postfix.push_back(out);
            }
            push(in);
        }
    }
    else{
        push(in);
    }
}


int checkPrec(char in){
    int level=0;
    switch(in){
        case '+':
        case '-':
            level=1;
            break;
        case '*':
        case '/':
            level=2;
            break;
        case '^':
            level=3;
            break;
    }
    return level;
}

void foundClosingBracket(char in){
    while(!isEmpty()){
        char out=pop();
        if(in==')' && out=='('){
            continue;
        }else if(in=='}' && out=='{'){
            continue;
        }else if(in==']' && out=='['){
            continue;
        }
        postfix.push_back(out);
    }
}

char peek(){
    if(isEmpty()){
        return '$';
    }
    return top->data;
}

char pop(){
    if(isEmpty()){
        return '$';
    }
    char out=top->data;
    delete top;
    top=top->next;
    return out;
}

bool isEmpty(){
    if(top==NULL){
        return true;
    }
    return false;
}

void push(char item){
    node *nptr;
    nptr=createNode(item);
    if(top==NULL){
        top=nptr;
    }else{
        nptr->next=top;
        top=nptr;
    }
}

node* createNode(char item){
    node* nptr;
    nptr=new node;
    nptr->data=item;
    nptr->next=NULL;
    return nptr;
}

