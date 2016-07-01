/*
    SOLVED

*/

#include<iostream>

struct node{
    std::string data;
    node* next;
    //node* prev;
};

node *root,*nptr,*tptr;

int searchNode(std::string);

int main(){
    int N,Q;
    root=NULL;

    //take input and insert into list
    std::cin>>N;
    std::cin.ignore(256,'\n');

    for(int i=0;i<N;i++){
        nptr=new node;
        getline(std::cin,nptr->data);
        nptr->next=NULL;
        //nptr->prev=NULL;
        if(root==NULL){
            root=nptr;
            tptr=nptr;
        }else{
            tptr->next=nptr;
            //nptr->prev=tptr;
            tptr=nptr;
        }
    }

//take input for query
    std::cin>>Q;
    std::cin.ignore(256,'\n');
    for(int i=0;i<Q;i++){
        std::string srch;
        getline(std::cin,srch);
        //cout<<srch<<endl;
        std::cout<<searchNode(srch)<<std::endl;
    }

    //test output
}

int searchNode(std::string str){
    tptr=root;
    int countNode=0;
    //node *post,*pre;

    while(tptr!=NULL){
        if(tptr->data==str){
            countNode++;
        }
        tptr=tptr->next;
    }
    /*

    while(tptr!=NULL){
        if(tptr->data==str){
            cout<<tptr->data<<endl;
            countNode++;
            post=tptr->next;
            pre=tptr->prev;
            pre->next=post;
            post->prev=pre;

            //delete tptr;
            tptr=post;
        }else{
            tptr=tptr->next;
        }
    }*/
    return countNode;
}
