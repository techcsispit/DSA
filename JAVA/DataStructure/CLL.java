package DS ;
public class CLL {

    int size;
    Node head;
    Node tail;

    public CLL() {
    }

    public void addFirst(int n) {

        Node node = new Node(n);
        node.next = head;
        if (tail != null) {
            tail.next = node;
        }
        head = node;
        if (tail == null) {
            tail = head;
            head.next = tail.next = head;
        }
        size++;
    }

    public void addLast(int n) {
        if (tail == null) {
            addFirst(n);
            return;
        }

        Node node = new Node(n);
        node.next = head;
        tail.next = node;
        tail = node;
        size++;
    }

    public void add(int i, int n) {
        if (i == 0) {
            addFirst(n);
            return;
        }
        if (i == size) {
            addLast(n);
            return;
        }

        Node temp = getNodeIndex(i - 1);
        Node node = new Node(n);
        node.next = temp.next;
        temp.next = node;
        size++;
    }

    public int removeFirst() {
        int value = head.value;
        head = head.next;
        tail.next = head;
        if (head == null) {
            tail = null;
        }
        size--;
        return value;
    }

    public int removeLast() {
        if (size == 1) {
            return removeFirst();
        }
        int val = tail.value;
        Node node = getNodeIndex(size - 2);
        node.next = head;
        tail = node;
        size--;
        return val;
    }

    public int remove(int i) {
        if (i == 0)
            return removeFirst();
        if (i == size - 1)
            return removeLast();
        Node node = getNodeIndex(i - 1);
        int value = node.value;
        node.next = node.next.next;
        size--;
        return value;
    }

    public int getSize() {
        return size;
    }

    public void print() {
        System.out.print("p ->");
        Node temp = head;
        int i = size;
        while (i > 0) {
            System.out.print(temp.value + "->");
            temp = temp.next;
            i--;
        }
        System.out.println("p");
    }

    public Node getNodeIndex(int i) {
        if (i < 0 || i >= size)
            return null;
        Node temp = head;
        while (i - 1 > 0) {
            temp = temp.next;
        }
        return temp;
    }

    class Node {
        int value;
        Node next;

        Node(int value) {
            this.value = value;

        }

        Node() {
        }

        Node(int value, Node next) {
            this.value = value;
            this.next = next;
        }
    }
    public static void main(String[] args) {
        CLL a = new CLL() ;
        a.addFirst(3);
        a.addLast(2);
        a.print(); 
        a.addFirst(4);
        a.print();
        a.addLast(4);
        a.print();
        a.removeFirst();
        a.print();
    }
    
}
