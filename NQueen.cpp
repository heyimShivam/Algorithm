/* C++ program to solve N Queen Problem using
backtracking */

/*
How to solve:-


1) Start in the leftmost column
2) If all queens are placed
    return true
3) Try all rows in the current column. 
   Do following for every tried row.
    a) If the queen can be placed safely in this row 
       then mark this [row, column] as part of the 
       solution and recursively check if placing
       queen here leads to a solution.
    b) If placing the queen in [row, column] leads to
       a solution then return true.
    c) If placing queen doesn't lead to a solution then
       unmark this [row, column] (Backtrack) and go to 
       step (a) to try other rows.
4) If all rows have been tried and nothing worked,
   return false to trigger backtracking.
   
   
   */

#include <bits/stdc++.h>
#define N 4
using namespace std;

void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << " " << board[i][j] << " ";
		printf("\n");
	}
}

d[N][N], int row, int col)
{
	int i, j;


	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;


	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}


bool solveNQUtil(int board[N][N], int col)
{
	/
	if (col >= N)
		return true;

	for (int i = 0; i < N; i++) {
		if (isSafe(board, i, col)) {
			board[i][col] = 1;


			if (solveNQUtil(board, col + 1))
				return true;
			board[i][col] = 0; 
		}
	}
	return false;
}
bool solveNQ()
{
	int board[N][N] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };

	if (solveNQUtil(board, 0) == false) {
		cout << "Solution does not exist";
		return false;
	}

	printSolution(board);
	return true;
}
int main()
{
	solveNQ();
	return 0;
}
