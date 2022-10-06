#include <bits/stdc++.h>
using namespace std;
 
int MatrixChainOrder(int p[], int i, int j) {
    if (i == j)
        return 0;
    int k,  mini = INT_MAX, count;
 
 
    for (k = i; k < j; k++) {
        count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        mini = min(count, mini);
    }

    return mini;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 3 };
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of multiplications is " << MatrixChainOrder(arr, 1, N - 1);

}
 