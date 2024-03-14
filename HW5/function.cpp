#include "function.h"
#include <iostream>

using namespace std;

template < class T >
void mysort(T arr[], int l, int r)
{   
    int temp;
    int a,b;
    if (l < r) {
        int pivot = arr[r];
        int i = l -1;
        for (int j = l; j < r; j++) {
            if (arr[j] < pivot) {
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        i++;
        temp = arr[i];
        arr[i] = arr[r];
        arr[r] = temp;
        pivot = i;
        mysort(arr, l, pivot - 1);
        mysort(arr, pivot + 1, r);
    }
}

void solve() 
{
    int n, l, r, c;
    int *T,*L, *R;
    int i = 0, j = 0;
    int count = 0;

    cin >> n;
    cin >> l;
    cin >> r;
    cin >> c;

    if (l < r) count = c * (r - l)/2;
    if (l > r) count = c * (l - r)/2;
    T = new int[n];
    L = new int[n];
    R = new int[n];
    for (i = 0; i < n/2; i++) {
        L[i] = 999999;
        R[i] = 999999;
    }

    for (i = 0; i < l; i++) {
        cin >> L[i];
    }
    while (j < r)
    {
        cin >> R[j++];
    }
    mysort(L, 0, n-1);
    mysort(R, 0, n-1);
    if (l < r) {
        for (i = 0; L[i] != 999999; i++);
        for (j = 0; j < (r - l)/2; j++) {
            L[i] = R[i];
            R[i] = 999999;
        }
        
    }
    if (l > r) {
        for (i = 0; R[i] != 999999; i++);
        for (j = 0; j < (l - r)/2; j++) {
            R[i] = L[i];
            L[i] = 999999;
        }
    }
    mysort(L, 0, n-1);
    mysort(R, 0, n-1);
    for (i = 0; i < n; i++) {
        if (L[i] != R[i])
            count = count + c;
    }
    cout << count <<"\n";
    


}