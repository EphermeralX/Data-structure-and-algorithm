template <class T> class ArrayStack
{

private:
    int flag;       
    int count ;     
    T *array;  

public:
    ArrayStack();
    ArrayStack(int count);
    ~ArrayStack();
    void push(T data);     
    T pop();      
    T peek();     
    int stackSize();
    int stackMaxSize();     
};