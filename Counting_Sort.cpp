Counting sort is a sorting technique based on keys between a specific range. It works by counting the number of objects having distinct key values (kind of hashing). Then do some arithmetic to calculate the position of each object in the output sequence. 

Characteristics of counting sort:
Counting sort makes assumptions about the data, for example, it assumes that values are going to be in the range of 0 to 10 or 10 – 99 etc, Some other assumptions counting sort makes are input data will be all real numbers.
Like other algorithms this sorting algorithm is not a comparison-based algorithm, it hashes the value in a temporary count array and uses them for sorting.
It uses a temporary array making it a non In Place algorithm.
Let us understand it with the help of an example.

For simplicity, consider the data in the range 0 to 9. 
Input data: {1, 4, 1, 2, 7, 5, 2}
Take a count array to store the count of each unique object.
scene00721

Now, store the count of each unique element in the count array
If any element repeats itself, simply increase its count.
scene00865

Here, the count of each unique element in the count array is as shown below:
Index:     0  1  2  3  4  5  6  7  8  9
Count:    0  2  2  0   1  1  0  1  0  0
scene01153

Modify the count array such that each element at each index stores the sum of previous counts.
Index:      0  1  2  3  4  5  6  7  8  9
Count:     0  2  4  4  5  6  6  7  7  7
The modified count array indicates the position of each object in the output sequence.
Find the index of each element of the original array in the count array. This gives the cumulative count.


Rotate the array clockwise for one time.
Index:     0 1 2 3 4 5 6 7 8 9 
Count:     0 0 2 4 4 5 6 6 7 7


  Output each object from the input sequence followed by increasing its count by 1.
  Process the input data: 1, 4, 1, 2, 7, 5, 2. Position of 1 is 0.
  Put data 1 at index 0 in output. Increase count by 1 to place next data 1 at an index 1 greater than this index.


After placing each element at its correct position, decrease its count by one.
#include <iostream>  
  
using namespace std;  
  
int getMax(int a[], int n) {  
   int max = a[0];  
   for(int i = 1; i<n; i++) {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max; //maximum element from the array  
}  
  
void countSort(int a[], int n) // function to perform counting sort  
{  
   int output[n+1];  
   int max = getMax(a, n);  
   int count[max+1]; //create count array with size [max+1]  
  
  
  for (int i = 0; i <= max; ++i)   
  {  
    count[i] = 0; // Initialize count array with all zeros  
  }  
    
  for (int i = 0; i < n; i++) // Store the count of each element  
  {  
    count[a[i]]++;  
  }  
  
   for(int i = 1; i<=max; i++)   
      count[i] += count[i-1]; //find cumulative frequency  
  
  /* This loop will find the index of each element of the original array in count array, and 
   place the elements in output array*/  
  for (int i = n - 1; i >= 0; i--) {  
    output[count[a[i]] - 1] = a[i];  
    count[a[i]]--; // decrease count for same numbers  
}  
  
   for(int i = 0; i<n; i++) {  
      a[i] = output[i]; //store the sorted elements into main array  
   }  
}  
  
void printArr(int a[], int n) /* function to print the array */  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout<<a[i]<<" ";  
}  
  
int main() {  
    int a[] = { 31, 11, 42, 7, 30, 11 };  
    int n = sizeof(a)/sizeof(a[0]);  
    cout<<"Before sorting array elements are - \n";  
    printArr(a, n);  
    countSort(a, n);  
    cout<<"\nAfter sorting array elements are - \n";    
    printArr(a, n);  
    return 0;  
}  
Time Complexity	 
Best	O(n+k)
Worst	O(n+k)
Average	O(n+k)
Space Complexity	O(max)
Stability	Yes

