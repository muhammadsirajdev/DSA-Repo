public class BinarySearch {
    public static void main(String[] args) {
        int []arr={1,2,3,4,5,6,7,8,9,10};
        int target=12;
        int s=0;
        int e=arr.length-1;
        System.out.println(search( arr,target,s,e));


    }
    static int search(int arr[],int target,int s,int e){
        if (s>e){
            return -1;  // not the base case just checked qki start kbi b end sa
            //bara nae ho skta
        }
        int m= s+(e-s)/2;   //e-s is lia kya h jb ak dfa half
        // ho chuka hga tb e ma sa s nikalna pryga

        if (arr[m]==target){
            return m; //returning the index
        }
        if (arr[m]<target){//target right side hga half ka
            return search(arr,target,m+1,e); //start ko middle +1 pa lao
            //jb b reccursion ma kuch kro to return krna
        }
        if (arr[m]>target){//target left side hga half ka
            return search(arr,target,s,m-1);//end ko middle -1 pa lao
        }
        return -1;
    }
}
