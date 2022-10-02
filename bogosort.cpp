// The algorithm successively generates permutations of its input until it finds one that is sorted.
//like, if bogosort is used to sort a deck of cards, it would consist of checking if the deck were in order, 
//and if it were not, one would throw the deck into the air, pick the cards up at random, 
//and repeat the process until the deck is sorted

//pseudo code:

// while  not Sorted(list) do
//        shuffle (list)
//        done




// C++ implementation of Bogo Sort
#include<bits/stdc++.h>
using namespace std;
bool isSorted(int a[], int n) //check if array is sorted or not
{
	while ( --n > 1 )
		if (a[n] < a[n-1])
			return false;
	return true;
}
void shuffle(int a[], int n) // generate permutation of the array
{
	for (int i=0; i < n; i++)
		swap(a[i], a[rand()%n]);
}

void bogosort(int a[], int n) // Sorts array a[0..n-1] using Bogo sort
{
	while ( !isSorted(a, n) )
		shuffle(a, n);    
    // if array is not sorted then shuffle
	// the array again
}

void printArray(int a[], int n)
{
	for (int i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
	bogosort(arr, n);
	printf("Sorted array :\n");
	printArray(arr,n);
	return 0;
}
