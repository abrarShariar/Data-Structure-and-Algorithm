#include<iostream>
#include<map>
using namespace std;

#define MALT 1
#define UNMALT 0

struct customer{
    map<int,int>choice;
};


void testOutput(customer*,int);

int main(){

    int test;   //no. of test cases
    cin>>test;
for(int t=0;t<test;t++){

    map<int,int>::iterator it;
    int N;  //no.of flavours
    int M;  //no. of customers
    cin>>N;
    cin>>M;

    int makeBatch[N];           //total no. of milkshakes to make
    for(int i=0;i<N;i++){
        makeBatch[i]=-1;
    }

    customer allCustomer[M];    //array to store all customers struct

    //take input for all customers
    for(int i=0;i<M;i++){
        customer c1;
        int T;                  //no.of choice of customer
        cin>>T;
        for(int j=0;j<T;j++){
            int X;              //flavour no.
            int Y;              // 1/0
            cin>>X>>Y;

            it=c1.choice.find(X);
            //if key is unique
            if(it==c1.choice.end()){
                c1.choice[X]=Y;
                continue;
            }else if(it!=c1.choice.end() && c1.choice[X]==1 && Y==0){
            //if key is not unique and 1 and Y=0
                c1.choice[X]=Y;
                continue;
            }
        }
        allCustomer[i]=c1;
    }


    bool isPossible=true;
    //proccess (loop over each milkshake)
    for(int i=0;i<N;i++){
        int key=i+1;
        //loop over all customers
        for(int j=0;j<M;j++){
            customer c1=allCustomer[j];

            for(map<int,int>::iterator it=c1.choice.begin();it!=c1.choice.end();it++){
                //check conditions for making milkshakes
                if(c1.choice.size()==1){
                    makeBatch[i]=it->second;
                    //break;
                }
                else if(it->first==key && makeBatch[i]==-1 && it->second==0){
                    makeBatch[i]=it->second;
                    //continue;
                }
                else if(it->first==key && makeBatch[i]!=-1 && c1.choice.size()==1){
                    isPossible=false;
                    //continue;
                }
            }

            if(!isPossible){
                break;
            }
        }
        if(!isPossible){
            break;
        }
    }


    //---------------test output----------------------------
    //testOutput(allCustomer,M);
    cout<<"Case #"<<t+1<<": ";
    if(isPossible){
        for(int i=0;i<N;i++){
            if(makeBatch[i]==-1){
                makeBatch[i]=0;
            }
            cout<<makeBatch[i]<<" ";
        }
    }else{
        cout<<"IMPOSSIBLE";
    }
    cout<<endl;
}
}


void testOutput(customer* parr,int sz){
    for(int i=0;i<sz;i++){
        cout<<"Custome: "<<i<<endl;
        customer c1=*(parr+i);
        for(map<int,int>::iterator it=c1.choice.begin();it!=c1.choice.end();it++){
            cout<<it->first<<" "<<it->second<<endl;
        }
        cout<<endl;
    }
}
