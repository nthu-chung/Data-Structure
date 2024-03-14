#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
using namespace std;


int main() {
    // add this line of  code at the beginning of you main function
    
    int T;
    int n;
    double x,y;
    double X,Y;

    int i,j,k;
    float *A, *B;
    double sum;

    
    cin >> T;
    while (T--)
    {
        i = 0;
        j = 0;
        k = 0;
        sum =0.0;
        cin >> n;
        A = new float[n];
        B = new float[n];
        for (i = 0; i < 2*n; i++) {
            cin >> x >> y;
            if (x != 0) {
                if (x < 0) {
                    x = x* (-1.0);
                }
                
                A[j++] = x;
            }
            if (y != 0) {
                if (y < 0){
                    y = y*(-1.0);
                }
                B[k++] = y;
            }
        }
        sort(A,A+n);
        sort(B,B+n);
 /*       for (i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << "\n";
        for (i = 0; i < n; i++) {
            cout << B[i] << " ";
        }
        cout << "\n";*/
        for (i = 0; i < n; i++) {
            X= A[i] * A[i];
            Y = B[i] * B[i];
            sum = sum + sqrt(X+Y);

 //           sum = sum + sqrt(A[i]*A[i] + B[i]*B[i]);
 //           cout << sum << "\n";
        }
        cout << fixed << setprecision(8) << sum <<"\n";
       
        
        

    }

  
    return 0;
    
}