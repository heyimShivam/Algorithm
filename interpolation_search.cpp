#include<bits/stdc++.h> 
using namespace std; 
   
int interpolation_search(int array[], int num, int x) 
{ 
   
    int st = 0, end = (num - 1); 
  
    while (st <= end && x >= array[st] && x <= array[end]) 
    { 
        if (st == end) 
        { 
            if (array[st] == x) return st; 
            return -1; 
        } 
        
        int pos = st + (((double)(end - st) / 
            (array[end] - array[st])) * (x - array[st]); 
  
        if (array[pos] == x) 
            return pos; 
  

        if (array[pos] < x) 
            st = pos + 1; 
  
        else
            end = pos - 1; 
    } 
    return -1; 
} 
  
int main() 
{ 
     
    int array[] = {10, 12, 13, 16, 18, 19, 20, 21, 
                 22, 23, 24, 33, 35, 42, 47}; 
    int num = sizeof(array)/sizeof(array[0]); 
  
    int x = 18; 
    int index = interpolation_search(arr, n, x); 
  

    if (index != -1) 
        cout << "Element found at index " << index; 
    else
        cout << "Element not found."; 
    return 0; 
} 
