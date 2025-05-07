public class d_llist_insertion {
    public static void displayall(Node head){
        Node temp= head;
        while (temp!=null){
            System.out.print(temp.data+"->");
            temp=temp.next;
        }
        System.out.println("null");
    }

//    display in reverse using tail
public static void displayall2(Node tail){
    Node temp= tail;
    while (temp!=null){
        System.out.print(temp.data+"->");
        temp=temp.prev;
    }
    System.out.println("null");
}
//isme hme koi random  ode given hga lkn phr b hme start sa end trk sari node
//    print krwani h
public static void display3(Node random){
        Node temp = random;
//        step1 move this temp_backward to the head
    while (temp.prev!=null){
        temp=temp.prev;
    }
//    now temp is at head
    while (temp!=null){
        System.out.print(temp.data+"->");
        temp=temp.next;
    }
    System.out.print("null");
}

//printing bothways in middle
    public static void display4(Node head ,int n){
        Node t1=head;
        Node t2=head;
        for (int i=1;i<=n;i++){
            t1=t1.next;
            t2=t2.next;
        }
        t2=t2.next;

        while (t1!=null){
            System.out.print(t1.data +"->");
            t1=t1.prev;
        }
        while (t2!=null){
            System.out.print(t2.data+"->");
            t2=t2.next;
        }
        System.out.println("null");
    }

    public static Node insertAt_head(Node head, int x){
        Node t= new Node(x);
        t.next=head;
        head.prev=t;
        head=t;
        return head;
    }
    public static Node insertAt_tail(Node head,int x){
        Node t= new Node(x);
        Node temp=head;
        while (temp.next!=null){
            temp=temp.next;
        }
        temp.next=t;
        t.prev=temp;
        t.next=null;
        return head;
    }

    public static Node insertAt_any_index(Node head, int indx){
        Node temp=head;
        Node x= new Node(90);
        for (int i=1;i<indx;i++){
            temp=temp.next;
        }
        x.next=temp.next;
        temp.next.prev=x;

        temp.next=x;
        x.prev=temp;
        return head;
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
        Node a= new Node(4);
        Node b= new Node(10);
        Node c = new Node(2);
        Node d= new Node(99);
        Node e = new Node(13);
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

        displayall(a);
        System.out.println(" ");
        displayall2(e);
        System.out.println("random");
        display3(d);
        System.out.println(" ");

        display4(a,3);

        System.out.println(" insertion");
        Node new_head=insertAt_head(a,30);
        System.out.println(new_head.data);

        System.out.println("insert At end");
        Node end= insertAt_tail(a,30);
        displayall(end);

        System.out.println("any index");
        Node any = insertAt_any_index(a,2);
        displayall(any);
    }
}
