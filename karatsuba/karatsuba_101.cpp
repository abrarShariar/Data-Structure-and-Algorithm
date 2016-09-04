/*
    testing Karatsuba multiplication algorithm (tested and works for n=1,n=2,n=3,n=4,n=5,n=6,n=7
    -- len=2 for all above cases

*/

#include<iostream>
#include<cmath>
using namespace std;

long int getNDigit(long int,long int);
long int getKaratsuba(long int,long int,long int);

int main(){

    long int num_x=1234561;
    long int num_y=5678901;
    long int len=7;
    //for some weird reason keep len=2

    //long int fx1=getNDigit(num_x,len/2);
    //long int fx2=num_x-fx1*pow(10,len/2);
    //cout<<fx1<<" "<<fx2<<endl;
    cout<<getKaratsuba(num_x,num_y,len)<<endl;
}

//karatsuba method
long int getKaratsuba(long int X,long int Y,long int n){

    if(n<=1){
        return X*Y;
    }
    long int mid=n/2;
    if(n%2!=0){
        mid=mid-1;
    }

    long int a=getNDigit(X,mid);
    long int b=X-a*pow(10,mid);
    long int c=getNDigit(Y,mid);
    long int d=Y-c*pow(10,mid);

    long int s1=getKaratsuba(a,c,mid);
    long int s2=getKaratsuba(b,d,mid);
    long int s3=getKaratsuba((a+b),(c+d),mid);
    long int res=s3-s2-s1;
    long int product=(pow(10,n)*s1) + pow(10,mid)*res + s2;
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


