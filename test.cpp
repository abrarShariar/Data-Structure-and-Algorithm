/* getchar example : typewriter */
#include<iostream>
#include<conio.h>
using namespace std;

int main ()
{
    cout<<"INPUT: ";
    while(true){
        char ch;
        ch=getche();
        if(ch=='X'){
            cout<<"INVALID";
        }else{
            cout<<"VALID";
        }
    }
}

