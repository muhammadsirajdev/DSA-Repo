public class reverseNumber {
    public static void main(String[] args) {
//        rev(1234);

        rev1(1234);//return the reversed value
        System.out.println(sum);

    }
    static void rev(int n){
        if (n==0){
            return;
        }
        System.out.println(n%10);
        rev(n/10);

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
}
