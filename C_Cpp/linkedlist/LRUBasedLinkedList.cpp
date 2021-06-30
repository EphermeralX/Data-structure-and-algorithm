typedef int DataType;

class SNode
{
public:
    DataType data;
    SNode * next;
};

class SList 
{
public:
    SList();
    SList(int MaxSize);
    ~SList();
    void intsertElemAtBegin(DataType x);      
    bool findElem(DataType x);              
    void deleteElemAtEnd();             
    bool deleteElem(DataType x);    
    bool isEmpty();                  
    bool isFull();                   
    void printAll();             

    void * findElemOptim(DataType x);     
    void deleteElemOptim(void * snode);     
private:
    int MaxSize;       
    int length;             
    SNode * head;         

};

#include<iostream>
using namespace std;


SList::SList(){
    head = new SNode;     
    head -> next = NULL;
    this -> MaxSize = 10;
    this -> length = 0;
}
SList::SList(int MaxSize){
    head = new SNode;     
    head -> next = NULL;
    this -> MaxSize = MaxSize;
    this -> length = 0;
}


SList::~SList(){
    SNode * ptr, * temp;
    ptr = head;
    while(ptr -> next != NULL){
        temp = ptr -> next;
        ptr -> next = ptr -> next -> next;
        delete temp;   
    }
    delete head ; 
    this -> head = NULL;
    this -> length = 0;
}


void SList::intsertElemAtBegin(DataType x){
    SNode * ptr = new SNode;
    ptr -> data = x;

    ptr -> next = head ->next;
    head -> next = ptr;

    this -> length ++;
}



bool SList::findElem(DataType x)
{
    SNode * ptr;
    ptr = head;
    while(ptr -> next != NULL){
        if(ptr -> next ->data == x){
            return 1;
        }
        ptr = ptr -> next;
    }
    return 0;
}


void SList::deleteElemAtEnd(){
    SNode * ptr , * temp;
    ptr = head;
    while(ptr -> next != NULL && ptr -> next -> next != NULL){   
        ptr = ptr -> next;
    }
    temp = ptr -> next;
    ptr -> next = temp -> next;
    this -> length --;
    delete temp;
}

bool SList::deleteElem(DataType x)
{
    SNode * ptr, * temp;
    ptr = head;
    while(ptr -> next != NULL){
        if(ptr -> next ->data == x){
            temp = ptr -> next;
            ptr -> next = temp -> next;
            delete temp;
            this -> length --;
            return 1;
        }
        ptr = ptr -> next;
    }
    return 0;
}


bool SList::isEmpty()
{
    if(this -> length == 0){  
        return 0;
    }
    else{
        return 1;
    }
}


bool SList::isFull()
{   
    if(this -> length == this -> MaxSize){  
        return 0;
    }
    else{
        return 1;
    }
}


void SList::printAll()
{
    SNode * ptr;
    ptr = head;
    while(ptr -> next != NULL){
        ptr = ptr -> next;
        cout << ptr-> data <<"   ";
    }
    cout << endl;
}     


void * SList::findElemOptim(DataType x)
{
    SNode * ptr;
    ptr = head;
    while(ptr -> next != NULL){
        if(ptr -> next ->data == x){
            return (void *)ptr;
        }
        ptr = ptr -> next;
    }
    return NULL;
}



void SList::deleteElemOptim(void * snode)
{
     SNode * ptr, * temp;
     ptr = (SNode *)snode;
     temp =  ptr -> next;
     ptr -> next = temp -> next;
     this -> length --;
     delete temp;
}
int main(int argc, char const *argv[])
{
    cout << "test "<< endl;   
    SList slist(10);     
    int num = 0;
    while(1)
    {
        cout << "please enter a number,99999== exit" << endl;
        cin >> num;
        if(num == 99999)
            break;
        SNode * prePtr = (SNode *)slist.findElemOptim(num);
        if(prePtr != NULL){    
            slist.deleteElemOptim(prePtr);     
            slist.intsertElemAtBegin(num); 
        }
        else{      
            if(slist.isFull()){    
                slist.intsertElemAtBegin(num);
            }
            else{       
                slist.deleteElemAtEnd();
                slist.intsertElemAtBegin(num);
            }
        }
        slist.printAll();
    }
    return 0;
    system("pause");
}