#include <bits/stdc++.h>
using namespace std;

int min(int x, int y) { return (x <= y) ? x : y; }
int fibonacciSearch(int arr[], int x, int n)
{
    int a = 0;
    int b = 1;
    int net = a + b;
    while (net < n)
    {
        a = b;
        b = net;
        net = a + b;
    }
    int negl = -1;
    while (net > 1)
    {
        int i = min(negl + a, n - 1);

        if (arr[i] < x)
        {
            net = b;
            b = a;
            a = net - b;
            negl = i;
        }

        else if (arr[i] > x)
        {
            net = a;
            b = b - a;
            a = net - b;
        }

        else
            return i;
    }
    if (b && arr[negl + 1] == x)
        return negl + 1;
    return -1;
}

int main()
{
    int num;
    cout << "Enter number of elements of array: ";
    cin >> num;
    int arr[num];
    cout << "Enter array elements: ";
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    cout << "Enter number of elements to search: ";
    cin >> x;

    int ind = fibonacciSearch(arr, x, n);
    if (ind >= 0)
        cout << "Found at index: " << ind;
    else
        cout << x << " => Not Found";
    return 0;
}