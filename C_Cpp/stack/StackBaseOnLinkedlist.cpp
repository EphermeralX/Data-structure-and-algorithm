#include <iostream>
#include "StackBaseOnLinkedlist.h"
using namespace std;

template<class T> LinkedListStack<T>::LinkedListStack()
{
    this -> count = 0;
    this -> head = new LinkedNode;
    this -> head -> next = NULL;
}

template<class T> LinkedListStack<T>::~LinkedListStack()
{
    LinkedNode * ptr, * temp;
    ptr = head;
    while(ptr -> next != NULL){
        temp = ptr -> next;
        ptr -> next = temp -> next;
        delete temp;   
    }
    delete head ; 
    this -> head = NULL;
    this -> count = 0;
}


template<class T> void LinkedListStack<T>::push(const T & data)
{
    LinkedNode * insertPtr = new LinkedNode;
    insertPtr -> data = data;
    insertPtr -> next = this -> head -> next;
    head -> next = insertPtr;
    this -> count ++;
    cout << "push data : " << this -> head -> next -> data << endl;  
}

template<class T> T LinkedListStack<T>::peek()
{
    if(this -> count == 0 || this -> head -> next == NULL){
        cout << " stack is empty, peek fail"<< endl;
        return NULL;
    }
    else{
        return this -> head -> next -> data;
    }
}


template<class T> T LinkedListStack<T>::pop()
{
    if(this -> count == 0 || this -> head -> next == NULL){
        cout << " stack is empty, pop fail"<< endl;
        return NULL;
    }
    else{
        LinkedNode * temp = this -> head -> next;
        this -> head -> next = temp -> next;
        T data = temp -> data;
        delete temp;
        this -> count --;
        return  data;
    }

}

template<class T> int LinkedListStack<T>::size() const
{
    return this -> count;
}             

int main(int argc, char const *argv[])
{
    cout << " === StackBasedOnLinkedList test begin ===" << endl;
    LinkedListStack <float> stack;
    cout << "size==="<<stack.size()<<endl;
    stack.push(10.1);
    stack.push(20.2);
    stack.push(30.);
    stack.push(40.4);
    stack.push(50.5);
    stack.push(60.6);
    cout << "size==="<<stack.size()<<endl;
    cout << "stack peek  " << stack.peek() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "size==="<<stack.size()<<endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "size==="<<stack.size()<<endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack peek  " << stack.peek() << endl;
    stack.push(110.1);
    stack.push(120.2);
    stack.push(130.3);
    stack.push(140.4);
    stack.push(150.5);
    stack.push(160.6);
    cout << "size==="<<stack.size()<<endl;
    cout << "stack peek  " << stack.peek() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack peek  " << stack.peek() << endl;   //peek
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "stack pop  " << stack.pop() << endl;
    cout << "size==="<<stack.size()<<endl;
    cout << "stack peek  " << stack.peek() << endl;   //peek
    cout << "stack pop  " << stack.pop() << endl;    
    system("pause");
    return 0;
}