public class productofdigits {
    public static void main(String[] args) {
        System.out.println(product(55));//if there is a 0 in input it will return 0
    }
    static int product(int n){
        if (n==0){   // last digit ko jb 10 sa divide krngy to 0 ayga
            return 1;
        }
        return (n%10)*product(n/10);
    }
}
