class LinearProbingHashTable<K, V> {
  private static class Entry<K, V> {
    private K key; 
    private V value;
    private boolean deleted;

    private Entry(K k, V v) {
      key = k;
      value = v;
      deleted = false;
    }
  }

  private int numEntries;
  Entry<K,V> table[];
  
  public LinearProbingHashTable(int size) {
    table = new Entry[size];
    numEntries = 0;
  } 
  
  public boolean insert(K key, V value) {
    if (key == null) // throws exception if null key
      throw new IllegalArgumentException("Error: key cannot be null");
    for (int i = 0; i < table.length; i++) 
      if (table[i] != null && table[i].value == value) // false if duplicate
        return false;
    for (int i = getHashTarget(key); i < table.length; i++) {
      if (table[i] == null || table[i].deleted) { // empty cell or reuses deleted entry
        table[i] = new Entry(key, value);  
        numEntries++;
        if (numEntries >= Math.round(table.length / 2)) // rehashes if table is half full
          rehash();
        return true;
      }
      if (i == table.length - 1)
        i = -1; // wrap around to start of table
    }
    return false;
  }

  public V find(K key) {
    for (int i = 0; i < table.length; i++) 
      if (table[i] != null && table[i].key == key)
        return table[i].value;
    return null; // not found
  }

  public boolean delete(K key) {
    if (find(key) == null) // false if not found
      return false;
    table[getHashLocation(key)].deleted = true; // entry remains; marked deleted
    numEntries--;
    return true;
  }

  private void rehash() {
    Entry<K,V> tempTable[] = table; // holds elements to be rehashed
    table = new Entry[table.length*2]; // doubled table size
    numEntries = 0;
    for (int i = 0; i < tempTable.length; i++) {
      if (tempTable[i] != null && !tempTable[i].deleted) // omits deleted items
        insert(tempTable[i].key, tempTable[i].value);
    }
  }

  public int getHashTarget(K key) {
    return key.hashCode() % table.length; // original index
  }

  public int getHashLocation(K key) {
    for (int i = getHashTarget(key); table[i] != null; i++) 
      if (table[i].key == key)
        return i; // current index
    return -1; // not found
  }

  public String toString() {
    String str = "";
    for (int i = 0; i < table.length; i++) {
      if (table[i] != null && !table[i].deleted)
        str += (i + " " + table[i].key + " " + table[i].value + "\n");
      else if (table[i] != null)
        str += (i + " " + table[i].key + " " + table[i].value + "  deleted \n");
      else
        str += (i + "\n"); // empty cell
    }
    return str;
  }
}
class Main {
  public static void main(String[] args) {
    LinearProbingHashTable table = new LinearProbingHashTable(7);
    // table.insert(null, "Sunday"); (throw error)
    table.insert(0, "Sunday"); // insert
    table.insert(1, "Monday");
    System.out.println(table.toString()); // toString
    System.out.println();
    table.insert(2, "Tuesday"); // rehash
    System.out.println(table.find(1)); // find
    System.out.println(table.find(5));
    System.out.println();
    System.out.println(table.toString());
    table.insert(2, "Wednesday");
    table.insert(20, "Thursday");
    table.insert(3, "Friday");
    System.out.println(table.getHashTarget(3)); // getHashTarget
    System.out.println(table.getHashLocation(3)); // getHashLocation
    System.out.println();
    System.out.println(table.toString());
    table.delete(2); // delete
    table.insert(0, "Saturday");
    System.out.println(table.toString());
    table.insert(100, "Thursday");
    table.insert(48, "Everyday");
    table.insert(49, "Someday");
    System.out.println(table.toString());
  }
}
