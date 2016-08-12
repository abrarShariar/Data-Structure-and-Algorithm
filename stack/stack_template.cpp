/*
    implementing Stack with linked list (using template class)
*/
#include<iostream>
using namespace std;


template<typename nodeType>struct node{
    nodeType data;
    node* next;
};


template<typename Type,typename node<Type>::nodeType>class Stack{
    private:
        int stackSize;
        typename node<Type>::nodeType* root;
        //int maxSize;
    public:
        Stack(){
            this->root=NULL;
            this->stackSize=0;
        };
        //stack methods
        void push(Type);
        Type pop();
        Type peek();
        void showStack();
};


//method to push new items into stack
template<typename Type,node<Type>::nodeType>void Stack<Type,node<Type> >::push(Type item){
    //create node
    node<Type> *nptr;
    nptr=new node<Type>;
    nptr->data=item;
    nptr->next=NULL;
    //push into stack (LIFO)
    if(this->root==NULL){
        this->root=nptr;
    }else{
        nptr->next=this->root;
        this->root=nptr;
    }
    this->stackSize=this->stackSize+1;
}

//method to display the contents of stack without removing
template<typename Type,typename nodeType>void Stack<Type,nodeType>::showStack(){
    //print all the items
    node<Type> *tptr;
    tptr=this->root;
    while(tptr!=NULL){
        cout<<tptr->data<<endl;
        tptr=tptr->next;
    }
    cout<<"Stack Size: "<<this->stackSize<<endl;
}

int main(){
    node<int>node_t
    Stack<int,node_t>stck;
    stck.push(10);
    stck.push(20);
    stck.push(30);

}
