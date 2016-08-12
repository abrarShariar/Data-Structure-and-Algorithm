/*
    STACK implemented using array (template class)
*/
#include<iostream>
using namespace std;

template<typename Type>class Stack{
    private:
        int stackSize=0;
        int top=-1;
        Type* stck=NULL;
    public:
        Stack(int stackSize){
            this->stackSize=stackSize;
            this->stck=new Type[stackSize];
        }
        ~Stack(){
            this->stck=NULL;
            delete this->stck;
            this->stackSize=0;
        }
        //push a new element in stack
        void push(Type item){
            if(this->top>=stackSize){
                cout<<"STACK FULL"<<endl;
                return;
            }
            this->top=this->top+1;
            this->stck[top]=item;
        };
        //pop item from stack (LIFO)
        Type pop(){
            if(this->top<0 || this->stackSize==0){
                cout<<"STACK EMPTY"<<endl;
                return NULL;
            }

            Type item=this->stck[this->top];
            this->top=this->top-1;
            return item;
        }
        //display stack (LIFO) without removing items
        void showStack(){
            if(this->top<0 || this->stackSize==0){
                cout<<"STACK EMPTY"<<endl;
                return;
            }
            for(int i=0;i<this->stackSize;i++){
                cout<<this->stck[i]<<endl;
            }
        }
};

int main(){



//ERROR CASE
    Stack<int>myStack(5);
    for(int i=0;i<10;i++){
        myStack.push(i+1);
    }

    myStack.showStack();
/*
    Stack<char>myStack(5);
    myStack.push('A');
    myStack.push('B');

    cout<<myStack.pop()<<endl;
    cout<<myStack.pop()<<endl;
    //ERROR
    cout<<myStack.pop()<<endl;
    cout<<myStack.pop()<<endl;

   Stack<double>myStack(2);
   myStack.showStack();
    Stack<int>myStack(5);
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    //ERROR
    myStack.push(1);
    */
}
