// C++ program to implement a
// real time optimized KMP
// algorithm for pattern searching

#include <iostream>
#include <set>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;
using std::set;
using std::cout;

// Function to print
// an array of length len
void printArr(int* F, int len,
			char name)
{
	cout << '(' << name << ')'
		<< "contain: [";

	// Loop to iterate through
	// and print the array
	for (int i = 0; i < len; i++) {
		cout << F[i] << " ";
	}
	cout << "]\n";
}

// Function to print a table.
// len is the length of each array
// in the map.
void printTable(
	unordered_map<char, int*>& FT,
	int len)
{
	cout << "Failure Table: {\n";

	// Iterating through the table
	// and printing it
	for (auto& pair : FT) {

		printArr(pair.second,
				len, pair.first);
	}
	cout << "}\n";
}

// Function to construct
// the failure function
// corresponding to the pattern
void constructFailureFunction(
	string& P, int* F)
{

	// P is the pattern,
	// F is the FailureFunction
	// assume F has length m,
	// where m is the size of P

	int len = P.size();

	// F[0] must have the value 0
	F[0] = 0;

	// The index, we are parsing P[1..j]
	int j = 1;
	int l = 0;

	// Loop to iterate through the
	// pattern
	while (j < len) {

		// Computing the failure function or
		// lps[] similar to KMP Algorithm
		if (P[j] == P[l]) {
			l++;
			F[j] = l;
			j++;
		}
		else if (l > 0) {
			l = F[l - 1];
		}
		else {
			F[j] = 0;
			j++;
		}
	}
}

// Function to construct the failure table.
// P is the pattern, F is the original
// failure function. The table is stored in
// FT[][]
void constructFailureTable(
	string& P,
	set<char>& pattern_alphabet,
	int* F,
	unordered_map<char, int*>& FT)
{
	int len = P.size();

	// T is the char where we mismatched
	for (char t : pattern_alphabet) {

		// Allocate an array
		FT[t] = new int[len];
		int l = 0;
		while (l < len) {
			if (P[F[l]] == t)

				// Old failure function gives
				// a good shifting
				FT[t][l] = F[l] + 1;
			else {

				// Move to the next char if
				// the entry in the failure
				// function is 0
				if (F[l] == 0)
					FT[t][l] = 0;

				// Fill the table if F[l] > 0
				else
					FT[t][l] = FT[t][F[l] - 1];
			}
			l++;
		}
	}
}

// Function to implement the realtime
// optimized KMP algorithm for
// pattern searching. T is the text
// we are searching on and
// P is the pattern we are searching for
void KMP(string& T, string& P,
		set<char>& pattern_alphabet)
{

	// Size of the pattern
	int m = P.size();

	// Size of the text
	int n = T.size();

	// Initialize the Failure Function
	int F[m];

	// Constructing the failure function
	// using KMP algorithm
	constructFailureFunction(P, F);
	printArr(F, m, 'F');

	unordered_map<char, int*> FT;

	// Construct the failure table and
	// store it in FT[][]
	constructFailureTable(
		P,
		pattern_alphabet,
		F, FT);
	printTable(FT, m);

	// The starting index will be when
	// the first match occurs
	int found_index = -1;

	// Variable to iterate over the
	// indices in Text T
	int i = 0;

	// Variable to iterate over the
	// indices in Pattern P
	int j = 0;

	// Loop to iterate over the text
	while (i < n) {
		if (P[j] == T[i]) {

			// Matched the last character in P
			if (j == m - 1) {
				found_index = i - m + 1;
				break;
			}
			else {
				i++;
				j++;
			}
		}
		else {
			if (j > 0) {

				// T[i] is not in P's alphabet
				if (FT.find(T[i]) == FT.end())

					// Begin a new
					// matching process
					j = 0;

				else
					j = FT[T[i]][j - 1];

				// Update 'j' to be the length of
				// the longest suffix of P[1..j]
				// which is also a prefix of P

				i++;
			}
			else
				i++;
		}
	}

	// Printing the index at which
	// the pattern is found
	if (found_index != -1)
		cout << "Found at index "
			<< found_index << '\n';
	else
		cout << "Not Found \n";

	for (char t : pattern_alphabet)

		// Deallocate the arrays in FT
		delete[] FT[t];

	return;
}

// Driver code
int main()
{
	string T = "cabababcababaca";
	string P = "ababaca";
	set<char> pattern_alphabet
		= { 'a', 'b', 'c' };
	KMP(T, P, pattern_alphabet);
}
