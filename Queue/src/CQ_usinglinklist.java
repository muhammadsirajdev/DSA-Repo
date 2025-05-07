public class CQ_usinglinklist {

    public static class Node{
        int data;
        Node next;

        Node(int data){
            this.data=data;
        }
    }
    public static class Cqlist{
        Node head =null;
        Node tail=null;
        int size=0;

        public  void add(int x){
            Node temp = new Node(x);
            if (size==0){
                head=tail=temp;
                size++;
            }else {
                tail.next=temp;
                tail=temp;
                tail.next=head;
                size++;
            }
        }
        public void remove(){
            tail.next=head.next;
            head=head.next;
            size--;
        }
        public  void display(){
            Node temp=  head;
            while (temp.next!=head){
                System.out.print(temp.data+"->");
                temp=temp.next;
            }
            System.out.print(temp.data +"->");
            System.out.println("null");
        }
    }
    public static void main(String[] args) {
        Cqlist ql = new Cqlist();
        ql.add(1);
        ql.add(2);
        ql.add(3);
        ql.add(4);
        ql.display();
        System.out.println(" ");
        ql.remove();
        ql.display();
        ql.remove();
        ql.display();

    }
}
