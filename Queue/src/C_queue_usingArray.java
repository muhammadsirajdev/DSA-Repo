public class C_queue_usingArray {
    public static class Cqarray{
        int f =-1;
        int r =-1;
        int size =0;
        int[] arr = new int[8];

        public void add(int x) throws Exception{
            if (size==arr.length){
                throw new Exception("Queue is full");
            }if (size==0){
                f=r=0;
                arr[0]=x;
                size++;
            } else if (r<arr.length-1) {
                r++;
                arr[r]=x;
                size++;
            } else if (r==arr.length-1) {
                r=0;
                arr[r]=x;
                size++;
            }
        }
        public void remove(){
            if (size==0){
                System.out.println("queue is empty");
            }else {
                f++;
                size--;
            }
        }
        public void peek(){
            System.out.println(arr[r]);
        }
        public void display(){
            if (size==0){
                System.out.println("empty");
                return;
            }else if(f<r) {
                for (int i=f;i<=r;i++){
                    System.out.print(arr[i]+" ");
                }
            } else if (f>r) {
                for (int i=f;i<=arr.length-1;i++){
                    System.out.print(arr[i]+" ");
                }f=0;
                for (int i=f;i<=r;i++){
                    System.out.print(arr[i]+" ");
                }
            }
        }
    }
    public static void main(String[] args)throws Exception {
        Cqarray q = new Cqarray();
        q.add(1);
        q.add(2);
        q.add(3);
        q.add(4);
        q.add(5);
        q.add(6);
        q.add(7);
        q.add(8);
        q.display();
        q.remove();
        System.out.println(" ");
        q.display();
        System.out.println(" ");
        q.add(9);
        q.display();
        System.out.println(" ");
        q.peek();




    }
}
