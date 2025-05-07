public class twosum {
    public static void two(Node head,int target){
        Node temp=head;
        while (temp.next!=null){
            temp=temp.next;
        }
        Node h=head;

        while (h.data!=temp.data){
            if (h.data+temp.data==target){
                System.out.println("the numbers are "+ h.data +" && "+temp.data);
                break;
            } else if (h.data+temp.data>target) {
                temp=temp.prev;
            }else {
                h=h.next;
            }
        }
    }
    public static class Node{
        int data;
        Node next;
        Node prev;

        Node(int data){
            this.data=data;
        }
    }

    public static void main(String[] args) {
        Node a= new  Node(3);
        Node b= new  Node(5);
        Node c= new  Node(8);
        Node d= new  Node(13);
        Node e= new  Node(100);
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
        int tar = 16;
        two(a,tar);
    }
}
