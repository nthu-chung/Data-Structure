#include <iostream>
#include <string>
#include <sstream>
using namespace std;



template < class T >
class BaseStack
{
public:
    // Constructor
    BaseStack();

    // Destructor
    ~BaseStack();

    // Check if the stack is empty
    bool empty();

    // Return the size of the stack
    int size();

    // Return the top element
    T& top();

    // Insert a new element at top
    void push(const T& item);

    // Delete one element from top
    void pop();

private:
    T* _stack;
    int _top;
    int capacity;
};

// TODO: Implement all member functions in BaseQueue
template < class T >
class BaseQueue
{
public:
    // Constructor
    BaseQueue();

    // Destructor
    ~BaseQueue();

    // Check if the stack is empty
    bool empty();

    // Return the size of the queue
    int size();

    // Return the front element
    T& front();

    // Insert a new element at rear
    void push(const T& item);

    // Delete one element from front
    void pop();

private:
    T* _queue;
    int _front, _rear;
    int capacity;
};

// TODO: Implement five types of command
void insert(int L);
string first_row(int L, bool print = false);
void query(int L);
void flush();
void reset(int L);

BaseQueue <char> *q = new BaseQueue <char>[100];
BaseStack <string> s;

int main (void) {
    int L; // empity slot
    
    return 0;
}

template < class T >
BaseStack<T>::BaseStack()   // Constructor
{ 
    capacity = 10000;
    _stack = new T[capacity];
    _top = -1;
}
template < class T >
BaseStack<T>::~BaseStack()  // Destructor
{

}
template < class T >
bool BaseStack<T>::empty()  // Check if the stack is empty
{
    return _top == -1;
}
template < class T >
int BaseStack<T>::size()    // Return the size of the stack
{
    return _top+1;
}
template < class T >
T& BaseStack<T>::top()  // Return the top element
{
    return _stack[_top];
}
template < class T >
void BaseStack<T>::push(const T& item)  // Insert a new element at top
{   
    int num = capacity;
    int i; 
    if (_top == capacity - 1) {
        T* temp = new T[2*capacity];
        for (i = 0; i < num; i++) {
            temp[i] = _stack[i];
        }
        delete []_stack;
        _stack = temp;
        capacity *= 2;
    }
    _stack[++_top] = item;
}
template < class T >
void BaseStack<T>::pop()    // Delete one element from top
{
     _stack[_top--].~T(); 
}




template < class T >
BaseQueue<T>::BaseQueue()   // Constructor
{
     capacity = 10000;
    _queue = new T[capacity];
    _front = 0;
    _rear = 0;
}
template < class T >
BaseQueue<T>::~BaseQueue()   // Destructor
{

}
template < class T >
bool BaseQueue<T>::empty()   // Check if the stack is empty
{
    return _front == _rear;
}
template <class T>
int BaseQueue<T>::size()     // Return the size of the queue
{
    return _rear - _front;
}
template <class T>
T& BaseQueue<T>::front()    // Return the front element
{
    return _queue[_front];
}
template <class T>
void BaseQueue<T>::push(const T& item)  // Insert a new element at rear
{
    int num = capacity;
    int i;
    if (_rear == capacity - 1) {
        T* temp = new T[2*capacity];
        for (i = 0; i < num; i++) {
            temp[i] = _queue[i];
        }

        delete []_queue;
        _queue = temp;
        capacity *= 2;
    }
    _queue[_rear++] = item; 
}
template <class T>
void BaseQueue<T>::pop()    // Delete one element from front
{
    _queue[_front++].~T();
}
/*template <class T> 
void ChangeSize(T*& a, const int oldSize, const int newSize)
{
    int num = oldSize;
    int i;
    T* temp = new T[newSize];
    for (i = 0; i < num; i++) {
        temp[i] = a[i];
    }

    delete []a;
    a = temp;
}*/

