public class reverselist {
    public static Node reverse(Node head){
        Node curr= head;
        Node prev = null;
        Node agla = null;
        while (curr!=null){
            agla=curr.next;
            curr.next=prev;
            prev=curr;
            curr=agla;
        }
        return prev;
    }
    public static void print(Node head){
        Node temp = head;
        while (temp!=null){
            System.out.print(temp.data+"->");
            temp=temp.next;
        }
        System.out.print("null");
    }
    public static class Node {
        Node next;
        int data;

        Node (int data){
            this.data=data;
        }
    }

    public static void main(String[] args) {
        Node a = new Node(1);
        Node b= new Node(2);
        Node c= new Node(3);
        Node d= new Node(4);
        Node e= new Node(5);
        Node f= new Node(6);
        a.next=b;
        b.next=c;
        c.next=d;
        d.next=e;
        e.next=f;

        Node x = reverse(a);
        print(x);
    }
}
