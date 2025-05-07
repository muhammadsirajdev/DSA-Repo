public class insertion_start {
    public static void main(String[] args) {
        int[] arr = new int[4];
        arr[0]=1;
        arr[1]=2;
        arr[2]=3;
        int si=0;
        int li=arr.length-1;
        if (arr[li]==0) {
            while (li != 0) {
                while (arr[li] == 0) {
                    li--;
                }
                arr[li + 1] = arr[li];
                arr[li] = 0;
            }
        }
        for (int element:arr){
            System.out.println(element);
        }
    }
}
