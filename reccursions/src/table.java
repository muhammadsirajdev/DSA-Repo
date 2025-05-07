public class table {
    public static void main(String[] args) {
        print(1 );
    }
//    static void print(int n){
//        if (n==0) {
//            return;
//        }
//        print(n-1);
//        System.out.println(8 + "*"+ n+" = "+ 8*n);
//    }
    static void print(int n){
        if (n==5){
            return;
        }
        System.out.println(n);
        print(n+1);
    }

}