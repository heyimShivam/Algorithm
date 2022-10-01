// Optimized approach of Bubble Sort Algorithm in C++
// Time Complexity : O(n^2)
// Space Complexity : O(1)

#include<bits/stdc++.h>
using namespace std;

// Optimized solution of bubbleSort
void bubblesort(vector<int> &v, int size){
    
    for(int i = 0;i < size-1; i++){
        bool swapped = false;
        for(int j = 0; j < size-i-1; j++) {
            if( v[j] > v[j+1] ){
                swap(v[j], v[j+1]);
                swapped = true;
            }
        }
        // Swapped is used to avoid the worst case complexity of buuble sort by not comparing all the elements of array if the array is sorted
        if(!swapped)
            break;
    }

}
// printing array
void printArray(vector<int> &v, int size) {
    for(int i = 0; i < size; i++){
        cout<<" "<<v[i];
    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    bubblesort(v, v.size());
    cout<<"Sorted Array: \n";
    printArray(v, v.size());
    return 0;
}

// input : 5
//         1 5 3 2 4
