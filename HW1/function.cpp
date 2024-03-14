#include "function.h"
#include <iostream>
#include <string>
using namespace std;

BaseQueue <char> *q = new BaseQueue <char>[100];
BaseStack <string> s;


template < class T >
BaseStack<T>::BaseStack()   // Constructor
{
    capacity = 1000000;
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
     capacity = 1000000;
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
    return (_rear - _front) == -1;
}
template <class T>
int BaseQueue<T>::size()     // Return the size of the queue
{
    if ((_rear - _front) >= 0) {
        return (_rear - _front) + 1;
    } else {
        return 0;
    }
}
template <class T>
T& BaseQueue<T>::front()    // Return the front element
{
    return _queue[_front];
}
template <class T>
void BaseQueue<T>::push(const T& item)  // Insert a new element at rear
{
    _queue[_rear++] = item; 
}
template <class T>
void BaseQueue<T>::pop()    // Delete one element from front
{
    _queue[_front++].~T();
}

void insert(int L)
{
    int start_pos;              // start to insert position
    int i, j, max;              // loop index & max size of q[i]
    int size_tmp;               // temp for queue size

    string a;                   // input string

    cin >> start_pos >> a;
    
    max = q[start_pos].size();  // initialize max
    for (i = 1; i < a.size(); i++) {
        if(q[start_pos + i].size() > max)
            max = q[start_pos + i].size();      // find max size
    }

    for (i = 0; i < a.size(); i++) {
        size_tmp = q[start_pos + i].size();
        for (j = 0; j < max - size_tmp; j++){
            q[i + start_pos].push('@');         // fill @ for space
        }
        q[i + start_pos].push(a[i]);            // fill input string
    }
}

string first_row(int L, bool print)
{
    string a;                       // bottom string
    int i;                          // loop index

    a[L] = '\0';
    for (i = 0; i < L; i++) {
        if(q[i].empty()) {
            a[i] = ' ';             // fill ' ' for space
        } else {
            a[i] = q[i].front();    // fill bottom string
        }
    }
    if (print) {
        cout << "BOTTOM_ROW\n";
        for(i = 0; i < L; i++)
            if(a[i] == ' ')
                cout << '~';
            else
                cout << a[i];           // output if print is true
        cout << endl;
    }

    return a;                       // return bottom string
}

void query(int L)
{
    string a;                       // input string
    string b = first_row(L, false); // first row string
    int i, j;                       // loop index
    int len;                        // length of input string

    cin >> a;
    len = a.size();

    for (i = 0; i < L - len + 1; i++) {
        for (j = 0; j < len && a[j] == b[i + j]; j++) {
            // match string
        }
        if (j == len) {
            s.push(a);              // put match string to stack
            for (j = 0; j < len; j++) {
                q[j + i].pop() ;    // remove match string
            }
            // first_row(L, true);   // BOTTOM_ROW debug output
            // cout << a << endl;   //match debug output
            return;                 // stop function
        }
    }
}

void flush()
{
    cout << "FLUSH\n";
    while (!s.empty()) {            // do until empty
        cout << s.top() << "\n";    // print top string
        s.pop();                    // remove it
    }
}

void reset(int L)
{
   int i;      // loop index

    for (i = 0; i < L; i++) {
        while (!q[i].empty()) {
            q[i].pop();             // clean q[i]
        }
    }
    while (!s.empty()) {
        s.pop();                    // clean stack
    }
}
