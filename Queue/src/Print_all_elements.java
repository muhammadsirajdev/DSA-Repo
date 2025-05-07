import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Print_all_elements {
    public static void main(String[] args) {
        Queue<Integer>q= new LinkedList<>();
        //print all elements using
        //add,remove,peek,size,k_extra queue
        System.out.println("add the elements");

        while (q.size()<=5){
            Scanner sc = new Scanner(System.in);
            q.add(sc.nextInt());
        }
        System.out.println(q);
        Queue<Integer>q2= new LinkedList<>();
        while (q.size()>0){
            q2.add(q.remove());
        }
//      ab print krny ka bad jo elements
        //new queue ma dala tha wo wapis purana ma dalo
        while (q2.size()>0){
            q.add(q2.poll());
        }
    }
}
