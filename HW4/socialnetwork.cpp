#include <iostream>
using namespace std;

int main(void)
{
    int N;
    int i, j;
    int **A;
    int start;

    cin >> N;
    A = new int*[N];
    for (i = 0; i < N; i++) {
        A[i] = new int[N];
    }
    for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (A[i][j] != 0) {
                start = i;
                i = N;
                j = N;
            }
        }
    }

    return 0;
}