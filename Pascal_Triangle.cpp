#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1010;

int nCr[MaxN][MaxN];

void Pascal_Triangle(int n) {
    for(int i = 0; i <= n; i++) {
        nCr[i][0] = nCr[i][i] = 1;
        for(int j = 1; j < i; j++) {
            nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
        }
    }
}

int main() {
    int n, r;
    cin >> n >> r;
    Pascal_Triangle(n);
    cout << nCr[n][r];
    return 0;
}
