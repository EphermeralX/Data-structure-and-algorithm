template<class T> class LinkedListStack
{
public:
    LinkedListStack();
    ~LinkedListStack();

    void push(const T & data);   
    T peek();                    
    T pop();                     
    int size() const;            
private:
    int count;                  
    struct LinkedNode
    {
        T data;
        LinkedNode * next;
    };
    LinkedNode * head;   
};