#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> ar, int k)
{

    sort(ar.begin(), ar.end());
  
    
    int opsNeeded = 0;
    for (int i = 0; i < k; i++) {
        opsNeeded += ar[k - 1] - ar[i];
    }
  
    int ans = opsNeeded;
  
    for (int i = k; i < ar.size(); i++) {
  
    
        opsNeeded = opsNeeded - (ar[i - 1] - ar[i - k]);
  
        
        opsNeeded += (k - 1) * (ar[i] - ar[i - 1]);
        ans = min(ans, opsNeeded);
    }
    return ans;
}
  

int main()
{
    vector<int> arr = { 3, 1, 9, 100 };
    int n = arr.size();
    int k = 3;
  
    cout << minOperations(arr, k);
  
    return 0;
}