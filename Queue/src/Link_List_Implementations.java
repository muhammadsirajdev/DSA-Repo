public class Link_List_Implementations {

        public static class Node{
            int data;
            Node next;

            Node(int data){
                this.data=data;
            }
        }
    public static class llist{
            Node head =null;
            int size=0;

            public  void add(int x){
                Node temp = new Node(x);
                temp.next=head;
                head=temp;
                size++;
            }
            public void remove(){
                Node temp = head;
                while (temp.next.next!=null){
                    temp=temp.next;
                }temp.next=null;
                size--;
            }
            public void display(){
                Node temp = head;
                while (temp!=null){
                    System.out.print(temp.data+"->");
                    temp=temp.next;
                }
                System.out.println("null");
            }
            public void displayrec(Node h){
                if (h==null)return;
                displayrec(h.next);
                System.out.print(h.data+"->");
            }
            public void dis(){
                displayrec(head);
                System.out.println("null");
            }

    }

    public static void main(String[] args) {
            llist list = new llist();
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);
        list.display();
        list.remove();
        System.out.println("after removing");
        list.display();
        list.dis();
        list.remove();
        System.out.println("after removing");
        list.dis();
        list.add(1);
        list.dis();
    }
}
