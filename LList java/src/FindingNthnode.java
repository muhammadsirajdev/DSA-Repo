import org.w3c.dom.Node;

public class FindingNthnode {

    public static Node nthnode(Node head, int x){
        Node fast = head;
        Node slow = head;

        for (int i =1;i<x;i++){
            fast= fast.next;
        }

        while (fast.next!=null){
            slow=slow.next;
            fast=fast.next;
        }
        return slow;
    }
    public static class Node{
        int data;
        Node next;
        Node(int data){
            this.data= data;
        }
    }


    public static void main(String[] args) {
        Node a = new Node(100);
        Node b = new Node(13);
        Node c = new Node(4);
        Node d = new Node(5);
        Node e = new Node(12);
        Node f = new Node(10);
        a.next=b;
        b.next=c;
        c.next=d;
        d.next=e;
        e.next=f;

        Node temp = nthnode(a,1);
        System.out.println(temp.data);

    }
}
