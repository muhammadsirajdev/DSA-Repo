public class pre_order {

    public static class Node  {
        int data;
        Node left=null;
        Node right=null;
        Node(int data){
            this.data=data;

        }
        public static class binarysearch{

            public static void inorder(Node node){
                if (node==null){
                    return;
                }
                System.out.println(node.data);
                inorder(node.left);
                inorder(node.right);

            }
        }
    }
    public static void main(String[] args) {
        Node root = new Node(100);
        root.left = new Node(20);
        root.right = new Node(200);
        root.left.left = new Node(10);
        root.left.right = new Node(30);
        root.right.left = new Node(150);
        root.right.right = new Node(300);
        System.out.println("In pre-order traversal ");
        Node.binarysearch.inorder(root);
    }
}
