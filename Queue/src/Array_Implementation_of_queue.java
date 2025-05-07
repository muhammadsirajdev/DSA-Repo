public class Array_Implementation_of_queue {
    public  static class queueA{
        int f=-1;
        int r=-1;
        int size=0;
        int []arr= new int[6];

        public void add(int x) {
            if (r == arr.length - 1) {
                System.out.println("Queue is full");
                return;
            }
            if (f == -1) {
                f = 0;
            }
            r++;
            arr[r] = x;
            size++;
        }

        public int pop(){
            int x = arr[f];
            f++;
            size--;
            return x;


        }
        void display(){
            if (size==0){
                System.out.println("Queue is empty");
                return;
            }else {
                for (int i=f;i<=r;i++){
                    System.out.print(arr[i]+" ");
                }
                System.out.println(" ");
            }
        }
        void isEmpty(){
            if (size==0){
                System.out.println("queue is empty");
                return;
            }else {
                System.out.println("queue isn't empty");
            }
        }
    }
    public static void main(String[] args) {

        queueA q= new queueA();
        q.add(1);
//        q.add(2);
//        q.add(3);
//        q.add(4);
//        q.add(5);
//        q.add(6);
//        System.out.println(q.size);
//        q.display();
//        q.pop();
//        q.display();
//        q.pop();
//        q.display();
//        q.pop();
        q.display();
//        q.pop();
//        q.display();
//        System.out.println(q.size);
//        q.pop();
//        q.isEmpty();
//        q.pop();
//        System.out.println(q.size);
//        q.isEmpty();
    }
}
