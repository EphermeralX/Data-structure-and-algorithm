package Java.skiplist;

public class SkipList {

    private static final float SKIPLIST_P = 0.5f;
    private static final int MAX_LEVEL = 16;
  
    private int levelCount = 1;
  
    private Node head = new Node(); 
  
    public Node find(int value) {
      Node p = head;
      for (int i = levelCount - 1; i >= 0; --i) {
        while (p.forwards[i] != null && p.forwards[i].data < value) {
          p = p.forwards[i];
        }
      }
  
      if (p.forwards[0] != null && p.forwards[0].data == value) {
        return p.forwards[0];
      } else {
        return null;
      }
    }
  
    public void insert(int value) {
      int level = randomLevel();
      Node newNode = new Node();
      newNode.data = value;
      newNode.maxLevel = level;
      Node update[] = new Node[level];
      for (int i = 0; i < level; ++i) {
        update[i] = head;
      }
  
      // record every level largest value which smaller than insert value in update[]
      Node p = head;
      for (int i = level - 1; i >= 0; --i) {
        while (p.forwards[i] != null && p.forwards[i].data < value) {
          p = p.forwards[i];
        }
        update[i] = p;// use update save node in search path
      }
  
      // in search path node next node become new node forwords(next)
      for (int i = 0; i < level; ++i) {
        newNode.forwards[i] = update[i].forwards[i];
        update[i].forwards[i] = newNode;
      }
  
      // update node hight
      if (levelCount < level) levelCount = level;
    }
  
    public void delete(int value) {
      Node[] update = new Node[levelCount];
      Node p = head;
      for (int i = levelCount - 1; i >= 0; --i) {
        while (p.forwards[i] != null && p.forwards[i].data < value) {
          p = p.forwards[i];
        }
        update[i] = p;
      }
  
      if (p.forwards[0] != null && p.forwards[0].data == value) {
        for (int i = levelCount - 1; i >= 0; --i) {
          if (update[i].forwards[i] != null && update[i].forwards[i].data == value) {
            update[i].forwards[i] = update[i].forwards[i].forwards[i];
          }
        }
      }
  
      while (levelCount>1&&head.forwards[levelCount]==null){
        levelCount--;
      }
  
    }

    private int randomLevel() {
      int level = 1;
  
      while (Math.random() < SKIPLIST_P && level < MAX_LEVEL)
        level += 1;
      return level;
    }
  
    public void printAll() {
      Node p = head;
      while (p.forwards[0] != null) {
        System.out.print(p.forwards[0] + " ");
        p = p.forwards[0];
      }
      System.out.println();
    }
  
    public class Node {
      private int data = -1;
      private Node forwards[] = new Node[MAX_LEVEL];
      private int maxLevel = 0;
  
      @Override
      public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("{ data: ");
        builder.append(data);
        builder.append("; levels: ");
        builder.append(maxLevel);
        builder.append(" }");
  
        return builder.toString();
      }
    }
  
}