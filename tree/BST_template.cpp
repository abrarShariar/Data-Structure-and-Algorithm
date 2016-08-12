#include<iostream>
using namespace std;

template<typename Type>class BinarySearchTree{
    private:
        int maxSize=0;
        int lastIndex=0;
        Type* tree;
        int root=0;
    public:

        BinarySearchTree(int maxSize){
            this->maxSize=2*maxSize;
            this->tree=new Type[maxSize];
            //initialize all to NULL
            for(int i=0;i<this->maxSize;i++){
                this->tree[i]=NULL;
            }
            //set root
            this->root=this->tree;
        }

        //insert node
        void insertNode(Type item){
            if(this->root >= this->maxSize){}
        }
};

int main(){

}
