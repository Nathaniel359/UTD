public class OutsidePrintjob extends Printjob {
  public OutsidePrintjob(String n, int p, int np) {
    super(n, p, np);
  }
  public int computeCost() {
    return numPages*10;
  }
}
