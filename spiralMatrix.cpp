#include <bits/stdc++.h>
using namespace std;

void spiralMatrix(int arr[][3])
{
    int row = 3;
    int col = 3;

    int count = 0;
    int total = row * col;

    int startRow = 0;
    int endRow = row - 1;
    int startCol = 0;
    int endCol = col - 1;

    while (count < total)
    {
        // printing starting row
        for (int index = startCol; index <= endCol && count < total; index++)
        {
            cout << arr[startRow][index];
            count++;
        }
        startRow++;
        // printing ending column
        for (int index = startRow; index <= endRow && count < total; index++)
        {
            cout << arr[index][endCol];
            count++;
        }
        endCol--;
        // printing ending row
        for (int index = endCol; index >= startCol && count < total; index--)
        {
            cout << arr[endRow][index];
            count++;
        }
        endRow--;
        // printing starting column
        for (int index = endRow; index >= startRow && count < total; index--)
        {
            cout << arr[index][startCol];
            count++;
        }
        startCol++;
    }
}

int main()
{
    int arr[3][3];

    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            cin >> arr[row][col];

    spiralMatrix(arr);
    return 0;
}
