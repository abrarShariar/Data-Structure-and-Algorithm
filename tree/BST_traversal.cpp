#include<iostream>
using namespace std;
#define MAX_SIZE 5

void inOrder(int);
int bTree[MAX_SIZE]={50,40,60,30,45};

int main(){
    inOrder(0);
}

void inOrder(int root){
    if(root>=MAX_SIZE){
        return;
    }
    inOrder(2*root+1);
    cout<<bTree[root]<<endl;
    inOrder(2*root+2);
}
