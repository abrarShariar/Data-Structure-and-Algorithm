#include<iostream>
using namespace std;

//hashnode class
template<typename K, typename V>
class HashNode {
    public:
        K key;
        V value;

    HashNode(K key, V value) {
        this->key = key;
        this->value = value;
    }
};

//hashmap class
template<typename K, typename V>
class HashMap {

    private:
        HashNode<K,V> **arr;
        int capacity;
        int tableSize;
        //dummy node
        HashNode<K,V> *dummy;

    public:
        HashMap(int capacity){
            this->capacity = capacity;
            this->tableSize = 0;
            this->arr = new HashNode<K,V>*[capacity];
            this->dummy = new HashNode<K,V>(-1,-1);
        }

        //hash function
        int hashCode(K key){
            return key%this->capacity;
        }

        //insert new Node
        void insertNode(K key, V value) {
            HashNode<K, V> *temp = new HashNode<K, V>(key, value);
            int hashIndex = this->hashCode(key);

            while(arr[hashIndex] != NULL && arr[hashIndex]->key != -1 && arr[hashIndex]->key != key){
                hashIndex++;
                hashIndex %= this->capacity;
            }

            if(this->arr[hashIndex] == NULL && this->arr[hashIndex]->key == -1) {
               this->tableSize++;
               this->arr[hashIndex] = temp;
            }
        }

        //get a particular node
        V getNode(K key){
            int hashIndex = this->hashCode(key);

            while(arr[hashIndex] != NULL){
                if(arr[hashIndex]->key == key){
                    return arr[hashIndex]->value;
                }
                hashIndex++;
                hashIndex%=this->capacity;
            }
            return NULL;
        }

        //delete node
        V deleteNode(K key){
            int hashIndex = this->hashCode(key);
            while(this->arr[hashIndex] != NULL){
                if(this->arr[hashIndex]->key == key){
                    HashNode<K,V> *temp = this->arr[hashIndex];
                    this->tableSize--;
                    this->arr[hashIndex] = this->dummy;
                    return temp->value;
                }
                hashIndex++;
                hashIndex%=this->capacity;
            }
            return NULL;
        }


        //display
        void display(){
            for(int i = 0;i < this->capacity;i++){
                if(arr[i] != NULL && arr[i]->key != -1){
                    cout<<" Index: " << i;
                    cout<<" Key: " << this->arr[i]->key;
                    cout<<" Value: "<< this->arr[i]->value<<endl;
                }
            }
        }



};



int main(){
    int capacity = 20;
    HashMap<int,int> *myHashMap = new HashMap<int, int>(capacity);
    myHashMap->insertNode(100,0);
    myHashMap->insertNode(200,1);
    myHashMap->insertNode(500,2);

    //myHashMap->display();
}

















