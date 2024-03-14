#include <sstream>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void) {
    int L;
    int T, R;
    int i,j,k;
    int start;
    int A[10][10];
    int size;
    int sum;
    //queue <int> *q = new queue <int>[10];
    string a;
    stringstream s1;

    
    cin >> T;
   
    for (i = 0; i < T; i++) {
         cin >> L >> R;
        for (j = 0; i < R; j++) {
            cin >> a;
            start = a[0];
            if (a[0] != j) {
                for (k = 1; k < L; k++) {
                    A[j][k] = 0;
                }
            } else {
                size = a.size();
                for (k = 1; k <= size; k++) {

                    A[j][k] = a[k];
                 
                }
                while (k <= L) A[j][k] = 0;
            }
           

        }   
         for (j = 0; j <= a[0]; j++) {
             for (k = 1; k <= L; k++) {
                 sum += A[j][k];
             } 
             A[j][0] = sum;
             if (sum != 0) {
                 cout << sum;
             }
         }
        A[10][10] = {0};
         cout <<"\n";
        
    }
    


    return 0;

}