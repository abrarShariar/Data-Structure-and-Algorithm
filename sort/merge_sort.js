// merge sort in js

const myArr = [10000,10, 4, 3, -9999 , 1, 5, 2, -100000];

const mergeSort = (arr) => {
  if(arr.length === 1){
    return arr;
  }
  let leftArr = mergeSort(arr.slice(0, (arr.length/2)));
  let rightArr = mergeSort(arr.slice((arr.length/2)));
  return merge(leftArr, rightArr);
  
}

const merge = (leftArr, rightArr) => {
  
  let resultArr = [];
  while(leftArr.length > 0 && rightArr.length > 0) {
    if(leftArr[0] < rightArr[0]){
      resultArr.push(leftArr[0]);
      leftArr.splice(0,1);
    } else {
      resultArr.push(rightArr[0]);
      rightArr.splice(0,1);
    }
  }
  
  leftArr.forEach(el => resultArr.push(el))
  rightArr.forEach(el => resultArr.push(el))
  
  return resultArr;
}



console.log(mergeSort(myArr));
