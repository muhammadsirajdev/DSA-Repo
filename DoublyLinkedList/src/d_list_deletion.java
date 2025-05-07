public class d_list_deletion {
    public static Node delete(Node head, int indx){
        Node temp=head;
        for (int i=1;i<indx;i++){
            temp=temp.next;
        }
        temp.next=temp.next.next;
        temp.next.next.prev=temp;
        return head;
    }
    public static Node delete_head (Node head){
        head=head.next;
        head.prev=null;
        return head;
    }
    public static Node delete_tail(Node head){
        Node temp = head;
        while (temp.next!=null){
            temp=temp.next;
        }
        temp=temp.prev;
        temp.next=null;
        return head;
    }
    public static void display(Node head){
        Node temp=head;
        while (temp!=null){
            System.out.print(temp.data+"->");
            temp=temp.next;
        }
        System.out.println("null");
    }
    public static class Node{
        Node prev;
        int data;
        Node next;
        Node (int data){
            this.data=data;
        }
    }

    public static void main(String[] args) {
        Node a=new Node(1);
        Node b=new Node(2);
        Node c=new Node(3);
        Node d=new Node(4);
        Node e=new Node(5);
        a.prev=null;
        a.next=b;
        b.prev=a;
        b.next=c;
        c.prev=b;
        c.next=d;
        d.prev=c;
        d.next=e;
        e.prev=d;
        e.next=null;

        Node delete= delete(a,2);
        display(delete);
        System.out.println(" ");
        Node d_head = delete_head(a);
        display(d_head);

        Node tail = delete_tail(a);
        display(tail);
    }
}
