// C++ program to implement recursive Binary Search
#include <bits/stdc++.h>
#include<iostream>
#include<conio.h>
using namespace std;

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		return binarySearch(arr, mid + 1, r, x);
	}
}

int main(void)
{
	
	
	int size=0;
	 cout<<"Enter Size of array: "<<endl;
	 cin>>size;
	 int arr[size];
	 
	 cout<<"Enter "<<size<<" integers in any order: "<<endl;
	 for(int i=0;i<size;i++)
	 {
	 cin>>arr[i];
	 }
	 int x;
	 cout<<"Enter value to be searched : "<<endl;
	 cin>>x;
 
	int result = binarySearch(arr, 0, size-1, x);
	(result == -1)
		? cout << "Element is not present in array"
		: cout << "Element is present at index " << result;
	getch();
	return 0;
	
}

