public class FindingIntersection{
    public static Node getintersect(Node headA, Node headB){
        Node tempA=headA;
        Node tempB = headB;
        int lenghtA=0;
        while (tempA!=null){
            lenghtA++;
            tempA=tempA.next;
        }
        int lenghtb=0;
        while (tempB!=null){
            lenghtb++;
            tempB=tempB.next;
        }
        tempA=headA;
        tempB=headB;
        if (lenghtA>lenghtb){
            int steps= lenghtA-lenghtb;
            for (int i=1;i<=steps;i++){
                tempA=tempA.next;
            }
        }else{
            int steps= lenghtb-lenghtA;
            for (int i=1;i<=steps;i++){
                tempB=tempB.next;
            }
        }
        while (tempA!=tempB){
            tempA=tempA.next;
            tempB=tempB.next;
        }
        return tempA;
    }
    public static class Node{
        int data;
        Node next;

        Node(int data){
            this.data=data;
        }
    }

    public static void main(String[] args) {
        Node a= new Node(87);
        Node b= new Node(100);
        Node c= new Node(13);
        Node d= new Node(4);
        Node e= new Node(5);
        Node f= new Node(12);
        Node g= new Node(8);
        a.next=b;
        b.next=c;
        c.next=d;
        d.next=e;
        e.next=f;
        f.next=g;


        Node h= new Node(90);
        Node i=new Node(9);
        h.next=i;
        i.next=e;
        Node s= getintersect(a,h);
        System.out.println(s.data);
    }
}
