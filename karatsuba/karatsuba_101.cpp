/*
    testing Karatsuba multiplication algorithm (works for n=1,n=2,n=4
    -- FIX FOR ODD NUMBERS AND {n}+6

*/

#include<iostream>
#include<cmath>
using namespace std;

long int getNDigit(long int,long int);
long int getKaratsuba(long int,long int,long int);

int main(){

    long int num_x=1234;
    long int num_y=5678;
    long int len=6;

    long int fx1=getNDigit(num_x,len/2);
    long int fx2=num_x-fx1*pow(10,len/2);
    //cout<<fx1<<" "<<fx2<<endl;

    cout<<getKaratsuba(num_x,num_y,len)<<endl;
}

//karatsuba method
long int getKaratsuba(long int X,long int Y,long int n){

    if(n<=1){
        return X*Y;
    }
    long int a=getNDigit(X,n/2);
    long int b=X-a*pow(10,n/2);
    long int c=getNDigit(Y,n/2);
    long int d=Y-c*pow(10,n/2);

    long int s1=getKaratsuba(a,c,n/2);
    long int s2=getKaratsuba(b,d,n/2);
    long int s3=getKaratsuba((a+b),(c+d),n/2);

    long int res=s3-s2-s1;

    long int product=(pow(10,n)*s1) + pow(10,n/2)*res + s2;
    //long int product=(pow(10,n)*getKaratsuba(a,c,n/2)) + (pow(10,n/2)*(getKaratsuba(a,d,n/2)+getKaratsuba(b,c,n/2))) + getKaratsuba(b,d,n/2);
    return product;
}

//get N-digits ommited number as passed by len
long int getNDigit(long int num,long int limit){
    for(long int i=0;i<limit;i++){
        num=num/10;
    }
    return num;
}


