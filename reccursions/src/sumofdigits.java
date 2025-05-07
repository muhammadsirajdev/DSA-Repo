public class sumofdigits {
    public static void main(String[] args) {
        System.out.println(sum(194832202));
    }
    static int sum(int n){
        if (n==0){   // last digit ko jb 10 sa divide krngy to 0 ayga
            return 0;
        }
        return (n%10)+sum(n/10);
    }
}
