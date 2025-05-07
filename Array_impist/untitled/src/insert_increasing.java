import java.util.Scanner;

public class insert_increasing {
    public static void main(String[] args) {
        int[] arr = new int[5];

        int si = 0;
        int li = arr.length - 1;

        for (int i = 0; i < arr.length; i++) {
            System.out.println("Enter the element:");
            Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();

            if (arr[li] == 0) {
                if (arr[si] == 0) {
                    arr[i] = n;
                } else {
                    if (arr[si] < n) {
                        while (si < arr.length && arr[si] < n && arr[si] != 0) {
                            si++;
                        }
                        for (int j = li; j > si; j--) {
                            arr[j] = arr[j - 1];
                        }
                           arr[si] = n;
                    }
                    else {
                        for (int j = li; j > si; j--) {
                            arr[j] = arr[j - 1];
                        }
                        arr[si] = n;
                    }
                }
            }
        }
            for (int element : arr) {
                System.out.println(element);
            }
        }
    }

