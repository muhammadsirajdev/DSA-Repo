public class pallindrome {
    public static void main(String[] args) {
        System.out.println(Palindrome(1234321));
    }
    static int sum=0;
    static void rev1(int n){
        if (n==0){
            return ;
        }
        int rem=n%10;
        sum=sum*10+rem;
        rev1(n/10);
    }
    static boolean Palindrome(int n){
        rev1(n);
        return n==sum;
    }
}
