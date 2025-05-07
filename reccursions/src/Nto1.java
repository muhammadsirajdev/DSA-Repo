public class Nto1 {
    public static void main(String[] args) {
        fun(5);
        System.out.println(" ");
        fin(5);
    }
    static  void fun(int n){
        if (n==1){
            System.out.println(n);
            return;
        }
        System.out.println(n);
        fun(n-1);
    }
    static void fin(int n){
        if (n==1){
            System.out.println(n);
            return;
        }

        fin(n-1);
        System.out.println(n);
    }
}
