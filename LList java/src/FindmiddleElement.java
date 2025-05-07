public class FindmiddleElement {
    public static Node middle(Node head){
//        Node temp = head;
//        int size =0;
//        while (temp!=null){
//            size++;
//            temp=temp.next;
//        }
//        temp=head;
//        if (size%2!=0){
//            int a =size+1;
//            for (int i=1;i<=(a/2)-1;i++){
//                temp=temp.next;
//            }
//        }else {
//            for (int i=1;i<=(size/2)-1;i++){
//                temp=temp.next;
//            }
//        }
//        return temp;
        Node slow = head;
        Node fast = head;
        while (fast.next!=null && fast.next.next !=null){
            slow= slow.next;
            fast=fast.next.next;
        }
        return slow;
    }
     public static class Node {
        int data;
        Node next;

        Node(int data){
            this.data=data;
        }
    }

    public static void main(String[] args) {
        Node a = new Node(1);
        Node b = new Node(2);
        Node c = new Node(3);
        Node d = new Node(4);
        Node e = new Node(5);
        Node f = new Node(6);

        a.next=b;
        b.next=c;
        c.next=d;
        d.next=e;
        e.next=f;

        Node x = middle(a);
        System.out.println(x.data);
    }

}
