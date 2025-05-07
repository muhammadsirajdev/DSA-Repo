public class Removeduplicates {
    public static Node duplicate(Node head1){
        Node t= head1;
        Node head = new Node(100);
        Node temp=head;
        while (t!=null){
            if (t.data!=temp.data){
                temp.next=t;
                temp=t;

            }
            t=t.next;
        }
        temp.next = null;
        return head.next;
    }
    public static void print(Node head){
        Node temps = head;
        while (temps!=null){
            System.out.print(temps.data+"->");
            temps=temps.next;
        }
        System.out.println("null");
    }
    public static class Node {
        int data;
        Node next;

        Node (int data){
            this.data=data;
        }
    }

    public static void main(String[] args) {
        Node a= new Node(1);
        Node b= new Node(1);
        Node c= new Node(2);
        Node d= new Node(2);
        Node e= new Node(3);
        Node f= new Node(4);
        Node g= new Node(5);
        Node h= new Node(5);


        a.next=b;
        b.next=c;
        c.next=d;
        d.next=e;
        e.next=f;
        f.next=g;
        g.next=h;

        Node x= duplicate(a);
        print(x);
    }

}
