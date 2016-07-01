/*
    SOLVED
    ARRAY LEFT ROTATION
    https://www.hackerrank.com/challenges/array-rotation-2
*/

#include<iostream>

int main(){
    int d,N,head=0,tail;
    //take input
    std::cin>>N>>d;
    int arr[N];

    for(int i=0;i<N;i++){
        std::cin>>arr[i];
    }
    head=head+d;
    tail=N-1;

    int i=head;
    do{
        std::cout<<arr[i]<<" ";
        i++;
         if(i==tail+1){
            i=0;

        }
    }while(i!=head);
}
