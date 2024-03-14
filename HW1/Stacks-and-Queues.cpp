#include <queue>
#include <stack>
#include <iostream>
#include <string>
using namespace std;

/*
In partial judge problem, you need to compile two .cpp files and a header file together.
For compile multiple .cpp files and .h headers, please refer to the following tutorial.
Chinese:
https://github.com/htchen/i2p-nthu/blob/master/%E7%A8%8B%E5%BC%8F%E8%A8%AD%E8%A8%88%E4%B8%80/%E5%A6%82%E4%BD%95compile%E5%A4%9A%E5%80%8B%E6%AA%94%E6%A1%88/%E5%A6%82%E4%BD%95%20compile%20%E5%A4%9A%E5%80%8B%E6%AA%94%E6%A1%88.md
English (terminal command):
https://stackoverflow.com/questions/3202136/using-g-to-compile-multiple-cpp-and-h-files

For Dev C++ or other IDE, please search for the Internet.
*/

void insert(int L);
string first_row(int L, bool print = false);
void query(int L);
void flush();
void reset(int L);

queue <char> *q;
stack <string> s;

int main(void) {
    int L, C;
    string command;

    cin >> L >> C;

    q = new queue <char>[L];

    for (int i = 0; i < C; i++) {
        cin >> command;

        if (command == "INSERT") {
            insert(L);
        }
        else if (command == "BOTTOM_ROW") {
            first_row(L, true);
        }
        else if (command == "QUERY") {
            query(L);
        }
        else if (command == "FLUSH") {
            flush();
        }
        else if (command == "RESET") {
            reset(L);
        }
    }
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
