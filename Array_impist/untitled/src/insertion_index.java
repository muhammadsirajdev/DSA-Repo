import java.util.Scanner;

public class insertion_index {
    public static void main(String[] args) {
        int[] arr1 = new int[5];
        arr1[0] = 1;
        arr1[1] = 2;
        arr1[2] = 3;
        arr1[3] = 4;
        arr1[4] = 5;
        int si = 0;
        int li = arr1.length - 1;
        int indx = 0;
        if (indx < arr1.length && indx>-1) {
            if (arr1[li] == 0) {
                while (li != indx) {
                    while (arr1[li] == 0) {
                        li--;
                    }
                    arr1[li + 1] = arr1[li];
                    arr1[li] = 0;
                }
                arr1[li]=7;
                for (int element : arr1) {
                    System.out.println(element);
                }

            }else {
                System.out.println("Array is alredy full");
            }
        }
    }
}
