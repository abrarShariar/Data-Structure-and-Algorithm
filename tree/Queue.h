/*
        Queue template class
        - ENQUEUE
        - DEQUEUE
        - IS_EMPTY
*/
#include<iostream>
using namespace std;

template<typename Type>class Queue{
    private:
        int maxSize=0;
        int head;
        int rear;
        Type *que;
    public:
        Queue(int maxSize){
            this->maxSize=maxSize;
            this->que=new Type[maxSize];
            this->head=this->rear=0;
        }
        void enQueue(Type item){
            this->que[this->rear]=item;
            this->rear=this->rear+1;
        }
        Type deQueue(){
            Type temp=this->que[this->head];
            this->head=this->head+1;
            return temp;
        }

        bool isEmpty(){
            if(this->head>=this->rear && this->head!=0){
                return true;
            }
            return false;
        }
};
