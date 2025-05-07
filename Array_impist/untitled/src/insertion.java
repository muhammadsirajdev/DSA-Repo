import java.util.Scanner;

public class insertion {
    //at last
    public static void main(String[] args) {

       int []arr=new int[5];
       arr[0]=1;
       arr[1]=2;
       arr[2]=3;


       int a =0;
       int b=arr.length-1;

        if (arr[b]==0) {
            while (arr[a] != 0) {
                a++;
            }
            Scanner sc = new Scanner(System.in);
            System.out.println("add elements");

            arr[a] =sc.nextInt();

            for (int element:arr){
                System.out.println(element);
            }
        }

        else {
            System.out.println("space full");
        }

    }
}
