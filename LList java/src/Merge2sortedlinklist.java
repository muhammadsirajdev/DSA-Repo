public class Merge2sortedlinklist {
    public static Node merge(Node head1,Node head2){
        Node temp1= head1;
        Node temp2= head2;
        Node head = new Node(100);
        Node temp = head;
        while (temp1!=null && temp2!=null){
            if (temp1.data<temp2.data){
                Node a = new Node(temp1.data);
                temp.next=a;
                temp=a;
                temp1=temp1.next;
            }else {
                Node a = new Node (temp2.data);
                temp.next=a;
                temp=a;
                temp2=temp2.next;
            }
        }

        if (temp1==null){
            temp.next=temp2;
        }else{
            temp.next=temp1;
        }

        return head.next;
    }
    public static void list (Node head){
        Node temps =head;
        while (temps!=null){
            System.out.print(temps.data+"->");
            temps=temps.next;
        }
        System.out.print("null");
    }

  public static   class Node {
        Node next;
        int data;

        Node (int data){
            this.data=data;
        }

    }

    public static void main(String[] args) {
        Node a = new Node(1);
        Node b = new Node(3);
        Node c = new Node(5);
        Node d = new Node(8);
        Node e = new Node(9);
        a.next=b;
        b.next=c;
        c.next=d;
        d.next=e;

        Node g = new Node(2);
        Node h = new Node(4);
        Node i = new Node(6);
        Node j = new Node(7);
        g.next=h;
        h.next=i;
        i.next=j;

        Node func = merge(a,g);
        list(func);
    }
}
