public class Node {
  private String name;
  private Node next;
  
  public Node(String n, Node ne) {
    name = n;
    next = ne;
  }

  public void setName(String n) {
    name = n;
  }
  public void setNext(Node n) {
    next = n;
    return;
  }

  public String getName() {
    return name;
  }

  public Node getNext() {
    return next;
  }
}
