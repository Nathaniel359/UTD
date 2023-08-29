public class NameList {
  private Node head;
  private String print;
  
  public NameList() {
    head = new Node("", null);
  }

  public void add(String n) {
    if (n.length() < 2) {
      System.out.println("Name not added; must be 2 or more characters");
      return;
    }
    else {
      boolean letterNode = false;
      Node currNode = head.getNext();
      Node prevNode = head;
      if (currNode == null) { // if NameList is empty
        Node node = new Node(n, null);
        Node lNode = new Node(n.substring(0,1).toUpperCase(), node);
        head.setNext(lNode);
        System.out.println(n + " added");
        return;
      }
      else {
        while ((currNode != null) && (n.compareToIgnoreCase(currNode.getName()) >= 0)) {
          if (currNode.getName().compareToIgnoreCase(n.substring(0,1)) == 0) { // if a letter node already exists
            letterNode = true;
          }
          prevNode = currNode;
          currNode = currNode.getNext();
        }
        if (currNode == null) { // if name is at the end of the list
          Node node = new Node(n, null);
          if (!letterNode) { // adds a letter node
            Node lNode = new Node(n.substring(0,1).toUpperCase(), node);
            prevNode.setNext(lNode);
            System.out.println(n + " added");
            return;
          }
          prevNode.setNext(node);
          System.out.println(n + " added");
          return;
        }
        else { // if name is inserted in the middle of the NameList
          Node node = new Node(n, prevNode.getNext());
          if (!letterNode) { // adds a letter node
            Node lNode = new Node(n.substring(0,1).toUpperCase(), node);
            prevNode.setNext(lNode);
            System.out.println(n + " added");
            return;
          }
          prevNode.setNext(node);
          System.out.println(n + " added");
          return;
        }
      }
    }
  }

  public void remove(String n) {
    if (n.length() == 1) { // remove must be used to delete a name
      System.out.println("Error; names must be 2 or more characters long");
      return;
    }
    Node currNode = head.getNext();
    Node prevNode = head;
    Node prevPrevNode = prevNode;
    while (currNode != null) {
      if (n.equals(currNode.getName())) {
        prevNode.setNext(currNode.getNext()); // removal
        System.out.println(n + " removed");
        if (prevNode.getName().length() == 1 && (prevNode.getNext() == null || prevNode.getNext().getName().length() == 1)) { // if prevNode is a letter node and there are no words in between it and the end of the list or another letter node, remove prevNode
          prevPrevNode.setNext(prevNode.getNext());
          System.out.println(n.substring(0,1) + " removed as " + n + " was the last name that began  with it");
        }
        return;
      }
      prevPrevNode = prevNode; // iterating through list elements
      prevNode = currNode;
      currNode = currNode.getNext();
    }
    System.out.println("Failed to remove; name not found");
    return;
  }

  public void removeLetter(String n) {
    if (n.length() != 1) { // removeLetter must remove a single letter and all the names that begin with it
      System.out.println("Error; a single letter must be entered");
      return;
    }
    Node currNode = head.getNext();
    Node prevNode = head;
    while (currNode != null && !(currNode.getName().substring(0,1).compareToIgnoreCase(n) == 0)) {
      prevNode = currNode;
      currNode = currNode.getNext();
    }
    if (currNode == null) {
      System.out.println("Failed to remove letter; letter not found");
      return;
    }
    if (currNode.getName().substring(0,1).compareToIgnoreCase(n) == 0) {
      while (currNode != null && currNode.getName().substring(0,1).compareToIgnoreCase(n) == 0) {
        currNode = currNode.getNext(); // only currNode iterates through the elements so that all the words in between the letter node to be deleted (prevNode) and the next letter node or the end of the list get deleted
      }
      if (currNode == null) {
        prevNode.setNext(null);
        System.out.println(n + " and all the names beginning with " + n + " removed");
        return;
      }
      prevNode.setNext(currNode);
      System.out.println(n + " and all the names beginning with " + n + " removed");
      return;
    }
  }

  public boolean find(String n) {
    Node currNode = head.getNext();
    while (currNode != null) {
      if (n.equals(currNode.getName())) {
        return true;
      }
      currNode = currNode.getNext();
    }
    return false; // if loop terminates without returning true
  }

  public String toString() {
    String str = "";
    Node currNode = head.getNext();
    while (currNode != null) {
      if (currNode.getName().length() != 1) {
        str += "  ";
      }
      str += currNode.getName() + "\n";
      currNode = currNode.getNext();
    }
    return str;
  }
}
