#include <iostream>
using namespace std;

int main()
{
    int a[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(a) / sizeof(int);

    // sorting the array using selection sort

    for (int posn = 0; posn < n - 1; posn++)
    {
        int curr = a[posn];
        int min_posn = posn;

        // find the min element's index

        for (int i = posn; i < n; i++)
        {
            if (a[i] < a[min_posn])
            {
                min_posn = i;
            }
        }
        swap(a[posn], a[min_posn]);
    }

    cout << "The sorted array is: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    // now as the array is sorted, we have to print squares of all the elements

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = a[i] * a[i];
    }

    cout << "The squares of the sorted array is: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}