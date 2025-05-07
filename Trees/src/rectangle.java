public class rectangle {
    public static void print_num(int n){
        if (n==1){
            System.out.print(1+" ");
            return;
        }

        print_num(n-1);
        System.out.print(n+" ");
    }
    public static void main(String[] args) {
        int n=5;
        print_num(n);
    }
}