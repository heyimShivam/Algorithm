Heap Sort Algorithm
To solve the problem follow the below idea:

 First convert the array into heap data structure using heapify, than one by one delete the root node of the Max-heap and replace it with the last node in the
 heap and then heapify the root of the heap. Repeat this process until size of heap is greater than 1.

Follow the given steps to solve the problem:

Build a max heap from the input data. 
At this point, the maximum element is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of the heap by 1. 
Finally, heapify the root of the tree. 
Repeat step 2 while the size of the heap is greater than 1.

Detailed Working of Heap Sort
To understand heap sort more clearly, let’s take an unsorted array and try to sort it using heap sort.
Consider the array: arr[] = {4, 10, 3, 5, 1}.

Build Complete Binary Tree: Build a complete binary tree from the array.

Build complete binary tree from the array

Transform into max heap: After that, the task is to construct a tree from that unsorted array and try to convert it into max heap.

To transform a heap into a max-heap, the parent node should always be greater than or equal to the child nodes
Here, in this example, as the parent node 4 is smaller than the child node 10, thus, swap them to build a max-heap.
Transform it into a max heap image widget

Now, as seen, 4 as a parent is smaller than the child 5, thus swap both of these again and the resulted heap and array should be like this:

Repeat the above steps and it will look like the following:
Now remove the root (i.e. 3) again and perform heapify.
Now when the root is removed once again it is sorted. and the sorted array will be like arr[] = {1, 3, 4, 5, 10}.

// C++ program for implementation of Heap Sort

#include <iostream>
using namespace std;

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i)
{

	// Initialize largest as root
	int largest = i;

	// left = 2*i + 1
	int l = 2 * i + 1;

	// right = 2*i + 2
	int r = 2 * i + 2;

	// If left child is larger than root
	if (l < N && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest
	// so far
	if (r < N && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected
		// sub-tree
		heapify(arr, N, largest);
	}
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

	// Build heap (rearrange array)
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);

	// One by one extract an element
	// from heap
	for (int i = N - 1; i > 0; i--) {

		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

// A utility function to print array of size n
void printArray(int arr[], int N)
{
	for (int i = 0; i < N; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// Driver's code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	heapSort(arr, N);

	cout << "Sorted array is \n";
	printArray(arr, N);
}
