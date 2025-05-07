import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Queue;

public class queue {
    public static void main(String[] args) {
        //queue can be initialized in 2 ways
        //1)using Arra list,
        //2)using linkedlist
//        Queue<Integer>q = new ArrayDeque<>()
//        Queue<Integer>q =new LinkedList<>();

        Queue<Integer>q =new LinkedList<>();
        q.add(1);
        q.add(2);
        q.add(3);
        q.add(4);
        q.add(5);
        System.out.println(q);
        q.remove();
        //q.remove or q.poll both performs same functions
        System.out.println(q);

        System.out.println(  q.peek());
        System.out.println("size: ");
        System.out.println(q.size());
        q.add(1);
        System.out.println(q);
        System.out.println("size: ");
        System.out.println(q.size());
    }
}