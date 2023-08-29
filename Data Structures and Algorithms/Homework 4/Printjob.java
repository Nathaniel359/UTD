public class Printjob implements Comparable<Printjob> {
  protected String name;
  protected int priority;
  protected int numPages;

  public Printjob(String n, int p, int np) {
    name = n;
    priority = p;
    numPages = np;
  }

  public int computeCost() {
    return 0;
  }
  
  public int compareTo(Printjob p) {
    return (this.priority * this.numPages) - (p.priority * p.numPages);
  }
}
