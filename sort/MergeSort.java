//Merge Sort implemented in Java
public class MergeSort{
  //merge method
    public static void Merge(int[] arr,int p,int q,int r){
        int lSize=(q-p)+1;
        int rSize=r-q;
        int[] lArr=new int[lSize];
        int[] rArr=new int[rSize];

        //copy elements
        for(int i=0;i<lSize;i++){
          lArr[i]=arr[p+i];
        }
        for(int i=0;i<rSize;i++){
          rArr[i]=arr[q+1+i];
        }

        //sort and merge
        int li=0,ri=0,ki=p;
        while(li<lSize && ri<rSize){
            if(lArr[li] < rArr[ri]){
              arr[ki]=lArr[li];
              li++;
            }else{
              arr[ki]=rArr[ri];
              ri++;
            }
            ki++;
        }

        //deal with left-overs
        while(li<lSize){
          arr[ki]=lArr[li];
          li++;
          ki++;
        }
        while(ri<rSize){
          arr[ki]=rArr[ri];
          ri++;
          ki++;
        }
    }
  //mergesort method
    public static void getMergeSort(int[] array,int p,int r){
        //divide and conquer
          if(p<r){
              int q=(p+r)/2;
              getMergeSort(array,p,q);
              getMergeSort(array,q+1,r);
              Merge(array,p,q,r);
          }
        }

    public static void main(String[] args){
          int[] array={5,4,3,1};
          getMergeSort(array,0,array.length-1);
          for(int i=0;i<array.length;i++){
            System.out.println(array[i]);
          }
    }
}
