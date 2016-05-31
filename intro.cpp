#include<iostream>
#include<cctype>
using namespace std;

int main(){

   enum direction{
    north='n',
    south='s',
    east='e',
    west='w'
   };

    direction dir;
    string input;
    cout<<"ENTER DIRECTION: ";
    getline(cin,input);
    for(int i=0;i<input.length();i++){
        input[i]=tolower(input[i]);
    }

    if(input=="north"){
        dir='n';
    }else if(input=="south"){
        dir=south;
    }else if(input=="east"){
        dir=east;
    }else if(input=="west"){
        dir=west;
    }

    cout<<north<<endl;
}
