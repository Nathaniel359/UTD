class Main {
  public static void main(String[] args) {
    NameList list = new NameList();
    list.add("Dan");
    list.add("duncan");
    list.add("Sam");
    list.add("Danny");
    list.add("Sammy");
    list.add("heather");
    System.out.print(list.toString());
    list.add("Aaron");
    list.add("Wally");
    System.out.println(list.find("Danny"));
    System.out.println(list.find("Karen"));
    System.out.print(list.toString());
    list.remove("Karen");
    list.remove("Danny");
    System.out.println(list.find("Danny"));
    System.out.print(list.toString());
    list.remove("heather");
    System.out.print(list.toString());
    list.removeLetter("S");
    System.out.print(list.toString());
    System.out.println("Program has ended");
    list.remove("Wally");
    System.out.print(list.toString());
  }
}
