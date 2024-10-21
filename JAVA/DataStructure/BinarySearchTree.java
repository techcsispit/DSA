public class BinarySearchTree {
    class Node {
        int data;
        Node left;
        Node right;

        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    Node root = null;
    int n = 0;

    Node insert(Node root, int data) {
        if (root == null) {
            n++;
            return (new Node(data));
        }
        if (root.data > data) {
            root.left = insert(root.left, data);
        } else {
            root.right = insert(root.right, data);
        }
        return root;
    }

    BinarySearchTree(int data) {
        this.root = new Node(data);
    }

    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree(70);

        bst.insert(bst.root, 60);
        bst.insert(bst.root, 80);
        bst.insert(bst.root, 65);

        System.out.println(bst.n);
    }
}