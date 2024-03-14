#include <sstream>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(void) {
    int L;
    int T, R;
    int i,j,k;
    int start;
    int size;
    int sum;
    int temp = 0;
    queue <int> *q = new queue <int>[10];
    stack <int> s;
    string a;
    stringstream s1;

    
    cin >> T;
   
    for (i = 0; i < T; i++) {
         cin >> L >> R;
        for (j = 0; i < R; j++) {
            cin >> a;
            start = a[0];
            if (a[0] != j) {
                for (k = 1; k <= L; k++) {
                    q[j].push(0);
                }
            } else {
                size = a.size();
                for (k = 1; k <= size; k++) {

                    q[j].push(a[k]) ;
                 
                }
                while (k <= L) q[j].push(0);
            }
           

        }   
        for (j = a[0]; j >= 0 ; j--) {
           
            for (k = 1; k <= L; k++) {
                sum = temp + sum;
                sum += q[j].front();
                q[j].pop();
               
            }
            if (sum / 10 >= 1) {
                s.push(sum % 10);
                temp = sum / 10;
            } else {
                s.push(sum);
            } 
         }
         while (s.empty() == 0) {
            cout << s.top();
             s.pop();
         }
       
         cout <<"\n";
        
    }
    


    return 0;

}