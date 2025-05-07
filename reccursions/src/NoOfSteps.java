public class NoOfSteps {
    public static void main(String[] args) {
        System.out.println(steps(13528));
    }
    static int steps(int n){
        return helper(n,0);
    }
    static int helper(int n, int step){
        if (n==0){
            return step;
        }
        if (n%2==0){
            return helper(n/10,step+1);
        }
        if (n%2!=0){
            return helper(n-1,step+1);
        }
        return step;
    }
}
