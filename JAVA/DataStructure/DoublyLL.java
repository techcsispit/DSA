public class DoublyLL {
    private class Node {
        private int data;
        private Node prev;
        private Node next;

        private Node(int data) {
            this.data = data;
        }
    }

    Node start;

    public void insertAtStart(int data) {
        Node node = new Node(data);
        start.next = node;
    }

    public void insertAtEnd(int data) {
        Node node = start;
        while (node.next != null) {
            node = node.next;
        }
        Node newnode = new Node(data);
        node.next = newnode;
        newnode.prev = node;
    }

    public int deleteAtStart() {

        if (start == null) {
            return -1;
        }
        int data = start.next.data;
        start = start.next;
        return (data);
    }

    public int deleteAtEnd() {
        if (start == null) {
            return -1;
        }
        Node node = start;
        while (node.next != null) {
            node = node.next;
        }
        int data = node.data;
        node = node.prev;
        node.next = null;
        return (data);
    }

    public void deleteAtValue(int data) {
        if (start == null) {
            return;
        }
        Node node = start;
        while (node.next != null) {
            if (node.data == data) {
                Node temp = node.prev;
                node.next.prev = node.prev;
                temp.next = node.next;
            }
            node = node.next;
        }
    }
}
