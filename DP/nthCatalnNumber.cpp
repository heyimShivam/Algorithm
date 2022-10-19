#include <bits/stdc++.h>
using namespace std;
 
long int catalan(unsigned int n) {
    if (n <= 1)
        return 1;
    long long res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i) * catalan(n - i - 1);
 
    return res;
}
 
int main() {
    for (int i = 0; i < 10; i++)
        cout << catalan(i) << " ";
   
}