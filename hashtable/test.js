const CAPACITY = 10;
let hashTable = [];

class Node {
  constructor(name,fullname,skills) {
    this.name = name;
    this.fullName = fullname;
    this.skills = skills;
  }
}

//hash function
const getHashCode = (key) => {
  return key.split('').reduce((result,el) => {
    return result += el.charCodeAt(0);
  }, 0);
}

//hash to index
const getIndexFromHash = (hash) => {
  return hash%CAPACITY;
}

const insertNode = (node) => {
  let hash = getHashCode(node.name);
  hashTable[getIndexFromHash(hash)] = node;
}

const getNode = (key) => {
  let hash = getHashCode(key);
  return hashTable[getIndexFromHash(hash)];
}

const getIndex = (key) => {
  return getIndexFromHash(getHashCode(key));
}

//main functin
const main = () => {

  // test input
  console.log("n1 insert");
  let n1 = new Node('abrar1', 'abrar shariar 1', ['ES6', 'C++']);
  insertNode(n1);

  console.log("n2 insert");
  let n2 = new Node('abrar2', 'abrar shariar 2', ['ES6', 'C++']);
  insertNode(n2);

  console.log("n3 insert");
  let n3 = new Node('abrar3', 'abrar shariar 3', ['ES6', 'C++']);
  insertNode(n3);

  console.log("n4 insert");
  let n4 = new Node('abrar4', 'abrar shariar 4', ['ES6', 'C++']);
  insertNode(n4);

  console.log("n5 insert");
  let n5 = new Node('abrar5', 'abrar shariar 5', ['ES6', 'C++']);
  insertNode(n5);

  console.log("n6 insert");
  let n6 = new Node('abrar6', 'abrar shariar 6', ['ES6', 'C++']);
  insertNode(n6);

  console.log(getIndex('abrar1'));
  console.log(getIndex('abrar2'));
  console.log(getIndex('abrar3'));
  console.log(getIndex('abrar4'));
  console.log(getIndex('abrar5'));
  console.log(getIndex('abrar6'));

  console.log(getNode('abrar6'));

}


main();
