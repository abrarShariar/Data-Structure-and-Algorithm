#include<iostream>
#include <cstdlib>
using namespace std;

Node hashTable[10];

// class Node {
//   string name;
// }


int getHashCode(string key) {
  int result = 0;
  for(int i=0;i<key.length();i++){
    result += (int) key[i];
  }
  return result;
}

int getIndexFromHash(int hash){
  return (hash % sizeof(hashTable)/sizeof(hashTable[0]));
}

void insert(Node *node){
  int hash = getHashCode(node->name);
  hashTable[getIndexFromHash(hash)] = node;
}


void printAll(){
  for(int i=0;i<sizeof(hashTable)/sizeof(hashTable[0]);i++){
    cout<<hashTable[i]<<endl;
  }
}

int main() {

  insert(person);

  printAll();

}
