package Java.array;

public class Array{
    //Define an int array to store data
    public int[] data;
    //Define array length
    private int n;
    //Defines the number of elements in an array
    private int count;

    //constructors
    public Array(int capacity){
        this.data = new int[capacity];
        this.n = capacity;
        this.count = 0;
    }

    // find the element in the data and return by index
    public int find(int index){
        if (index < 0 || index >= count) return -1;
        return data[index];
    }

    // Insert elements: head insert, tail insert
    public boolean insert(int index, int value){
        // no elements in the array
        if (index == count && count == 0) {
           data[index] = value;
           ++count;
           return true;
        }

        // Array space full
        if (count == n) {
            System.out.println("There is no place to insert!");
            return false;
        }

        // If the count is not full, you can insert data into the array
        // illegal location
        if (index < 0||index > count ) {
            System.out.println("illegal location!");
            return false;
        }
        // legal location
        for( int i = count; i > index; --i){
            data[i] = data[i - 1];
        }
        
        data[index] = value;
        ++count;
        return true;
    }
    //Delete the elements in the array by index
    public boolean delete(int index){
        if (index <0 || index >= count) return false;
        //Starting from the delete position, move the following elements forward one bit
        for (int i = index+1; i < count; ++i){
            data[i-1] = data[i];
        }
        //Delete element at the end of array
        int[] arr = new int[count-1];
        for (int i=0; i < count-1;i++){
            arr[i] = data[i];
        }

        this.data = arr;
        --count;
        return true;
    }

    public void printAll() {
        for (int i = 0; i < count; ++i) {
            System.out.print(data[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Array array = new Array(5);
        array.printAll();
        array.insert(0, 0);
        array.printAll();
        array.insert(0, 5);
        array.printAll();
        array.insert(1, 2);
        array.printAll();
        array.insert(3, 14);
        array.printAll();
        array.insert(3, 13);
        array.printAll();
    }
}