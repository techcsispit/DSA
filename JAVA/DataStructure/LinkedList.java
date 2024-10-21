
public class LinkedList {
    public class Node {
        private int data;
        private Node next;

        private Node(int data) {
            this.data = data;
        }

    }

    private Node start;

    public void insertAtStart(int data) {
        Node node = new Node(data);
        node.next = start.next;
        start.next = node;
    }

    public void insertAtEnd(int data) {
        Node node = start;
        while (node.next != null) {
            node = node.next;
        }
        Node newNode = new Node(data);
        node.next = newNode;
        newNode.next = null;
    }

    public void deleteAtValue(int data) {
        // check if empty
        Node node = start;
        Node trail = null;
        while (node.next != null) {
            trail = node;
            node = node.next;

            if (node.data == data) {
                trail.next = node.next;
            }
        }

    }

}
