import java.lang.Math; // max function
class MySearchTree <AnyType extends Comparable<AnyType>> {
  class Node {
    private AnyType data;
    private Node leftChild;
    private Node rightChild;

    public Node(AnyType d, Node l, Node r) {
      data = d;
      leftChild = l;
      rightChild = r;
    }
  }

  protected Node root; 
  
  public MySearchTree() {
    root = null;
  }

  public Node add(AnyType d, Node c) {
    if (root == null) {
      root = new Node(d, null, null);
      return null;
    } // add root
    if (c == null) 
      return new Node(d, null, null); // base
    int compare = d.compareTo(c.data);
    if (compare == 0) {
      System.out.println(d + " already in the tree");
    }
    else if (compare < 0) {
      c.leftChild = add(d, c.leftChild);
    }
    else {
      c.rightChild = add(d, c.rightChild);
    }
    return c;
  }

  public boolean find(AnyType v, Node c) {
    if (c == null)
      return false; // not found
    int compare = v.compareTo(c.data);
    if (compare == 0) 
      return true; // value found
    else if (compare < 0) 
      return find(v, c.leftChild);
    else 
      return find(v, c.rightChild);
  }

  public int leafCount(Node c) {
    if (c == null)
      return 0;
    else if (c.leftChild == null && c.rightChild == null) // leaf
      return 1;
    else 
      return leafCount(c.leftChild) + leafCount(c.rightChild);
  }

  public int parentCount(Node c) {
    if (c == null)
      return 0;
    else if (c.leftChild == null && c.rightChild == null) // leaf
      return 0;
    else
      return 1 + parentCount(c.leftChild) + parentCount(c.rightChild);
  }

  public int height(Node c) {
    if (c == null) 
      return 0;
    else if (c.leftChild == null && c.rightChild == null)
      return 0;
    else // further depth
      return 1 + Math.max(height(c.leftChild), height(c.rightChild));
  }

  public boolean isPerfect(Node c) {
    if (height(c.leftChild) != height(c.rightChild))
      return false;
    else if ((c.leftChild == null && c.rightChild == null)) // leaf
      return true;
    if ((c.leftChild == null && c.rightChild != null) || (c.leftChild != null && c.rightChild == null)) // 1 child
      return false;
    else
      return isPerfect(c.leftChild) && isPerfect(c.rightChild);
  }

  public String ancestors(AnyType v, Node c) {
    if (find(v, root) == false)
      return "value not found";
    if (v.compareTo(c.data) == 0) // value; end of recursion
      return "";
    else if (v.compareTo(c.data) < 0)
      return String.valueOf(c.data) + " " + ancestors(v, c.leftChild);
    else 
      return String.valueOf(c.data) + " " + ancestors(v, c.rightChild);
  }

  public void inOrderPrint(Node c) {
    if (c == null)
      return;
    inOrderPrint(c.leftChild); // left -> parent -> right
    System.out.print(c.data);
    inOrderPrint(c.rightChild);
    return;
  }

  public void preOrderPrint(Node c) {
    if (c == null) 
      return;
    System.out.print(c.data);
    preOrderPrint(c.leftChild);
    preOrderPrint(c.rightChild); // parent -> left -> right
    return;
  }
}
class Main {
  public static void main(String[] args) {
    MySearchTree t = new MySearchTree();
    t.add(5, t.root);
    t.add(3, t.root);
    t.add(2, t.root);
    t.add(4, t.root);
    t.add(7, t.root);
    t.add(6, t.root);
    t.add(8, t.root);
    System.out.println(t.find(1, t.root));
    System.out.println(t.find(5, t.root));
    System.out.println("leaves: " + t.leafCount(t.root));
    System.out.println("parents: " + t.parentCount(t.root));
    System.out.println("height: " + t.height(t.root));
    System.out.println(t.isPerfect(t.root));
    System.out.println("ancestors: " + t.ancestors(2, t.root));
    t.inOrderPrint(t.root);
    System.out.println();
    t.preOrderPrint(t.root);
  }
}
