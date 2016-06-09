/*
    1
    2 3
    4 5 6
    7 8 9 0
    1 2 3 4 5
*/

#include<iostream>
using namespace std;
#define LIMIT 5

int main(){
    int line=0,element=0;

    while(line<LIMIT){
        for(int i=0;i<line+1;i++){
            element++;
            cout<<element%10<<" ";
        }
        cout<<endl;
        line++;
    }
}
