public class pallindrome {


//    check pallindrome
    public static boolean palindrom(Node head){
        Node temp = head;
        int size =0;
        while (temp.next!=null){
            temp=temp.next;
            size++;
        }
        Node t= temp;
        Node h= head;
        int i=0;
        while (i!=size/2){
            if (h.data!=t.data){
                return false;
            }
            h=h.next;
            t=t.prev;
            i++;
        }
        return true;
    }
    public static class Node{
        Node prev;
        int data;
        Node next;

        Node(int data){
            this.data=data;

        }
    }

    public static void main(String[] args) {
        Node a= new Node(1);
        Node b= new Node(2);
        Node c= new Node(3);
        Node d=new Node(3);
        Node e= new Node(2);
        Node f= new Node(1);
        a.prev=null;
        a.next=b;
        b.prev=a;
        b.next=c;
        c.prev=b;
        c.next=d;
        d.prev=c;
        d.next=e;
        e.prev=d;
        e.next=f;
        f.prev=e;
        f.next=null;

        boolean check = palindrom(a);
        System.out.println(check);
    }
}
