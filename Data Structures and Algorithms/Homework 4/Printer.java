import java.io.File;   
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Printer {
  private File file = new File("input.txt");
  private BinaryHeap binHeap = new BinaryHeap();
  
  public Printer() {
    try {
      Scanner reader = new Scanner(file);
      while (reader.hasNextLine()) {
        String line = reader.nextLine();
        String[] lineArr = line.split("	");
        if (lineArr[3].equals("I")) {
          binHeap.insert(new Printjob(lineArr[0], Integer.valueOf(lineArr[1]), Integer.valueOf(lineArr[2])));
        } // inside print job
        else {
          binHeap.insert(new OutsidePrintjob(lineArr[0], Integer.valueOf(lineArr[1]), Integer.valueOf(lineArr[2])));
        } // outside print job
      }
      reader.close();
    }
    catch (FileNotFoundException e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }

    while (!binHeap.isEmpty()) {
      Printjob currNode = (Printjob)binHeap.deleteMin();
      System.out.println("Name: " + currNode.name);
      System.out.println("User Priority: " + (currNode.priority));
      System.out.println("Pages: " + currNode.numPages);
      if (currNode instanceof OutsidePrintjob) {
        System.out.println("Cost: $" + currNode.computeCost() / 100 + "." + currNode.computeCost() % 100 + "\n");
      }
      else {
        System.out.println();
      }
    }
  }
  
  class Main {
      public static void main(String[] args) {
      Printer p = new Printer();
    }
  }
}
