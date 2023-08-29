import java.io.File;   
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashSet;

class TopSortGraph {
  class Edge {
    private String edgeFrom;
    private String edgeTo;

    public Edge(String n, String e) {
      edgeFrom = n;
      edgeTo = e;
    }
  }


  public TopSortGraph() {
    ArrayList<Edge> list = new ArrayList<Edge>();
    HashSet<String> sort = new HashSet<String>(); // used rather than another ArrayList to avoid duplicates
    // read in file
    File file = new File("graph.txt");
    try {
      Scanner reader = new Scanner(file);
      while (reader.hasNextLine()) {
        String line = reader.nextLine();
        String[] lineArr = line.split(" ");
        if (lineArr.length == 1) {
          list.add(new Edge(lineArr[0], lineArr[0]));
        } // used to include i in the sort
        for (int i = 1; i < lineArr.length; i++) {
          list.add(new Edge(lineArr[0], lineArr[i])); // each Edge added from a line of the .txt uses the first vertex as the edgeFrom and each other vertex as the edgeTo
        }
      }
    }
    catch (FileNotFoundException e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }
    
    boolean indegreeZero;
    while (!list.isEmpty()) {
      for (int i = 0; i < list.size(); i++) {
        indegreeZero = true;
        for (int j = 1; j < list.size(); j++) {
          if (list.get(i).edgeFrom.equals(list.get(j).edgeTo)) { // if a vertex has an incoming edge, its indegree is not zero
            indegreeZero = false;
            break;
          }
        }
        if (indegreeZero) { // 1: select a vertex with indegree zero
          sort.add(list.get(i).edgeFrom); // 2: add vertex to the sort
          list.remove(i); // 3: delete vertex and all emanating edges from the graph (it will take multiple iterations to completely delete a vertex with multiple emanating edges)
          i--;
        }
      }
    }
    for (String s : sort) {
      System.out.print(s + ", ");
    }
    System.out.println();
  }
}

class Main {
  public static void main(String[] args) {
    TopSortGraph t = new TopSortGraph();
  }
}
