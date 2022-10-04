#include <bits/stdc++.h>
using namespace std;

void recursive(string input, int l, int r)
{
    if (l == r)
    {
        cout << input << ", ";
        return;
    }
    for (int i = l; i <= r; i++)
    {
        swap(input[l], input[i]);

        recursive(input, l + 1, r);

        swap(input[l], input[i]);
    }

    return;
}

void iterative(string str)
{
    sort(str.begin(), str.end());
    while (true)
    {
        cout << str << ", ";
        int i = str.length() - 1;
        while (str[i - 1] >= str[i])
            if (--i == 0)
                return;

        int j = str.length() - 1;
        while (j > i && str[j] <= str[i - 1])
            j--;

        swap(str[i - 1], str[j]);
        reverse(str.begin() + i, str.end());
    }
}

int main()
{
    string str;
    cin >> str;
    int n = str.length();

    cout << "recursive:- " << endl;
    recursive(str, 0, n - 1);

    cout << "iterative:- " << endl;
    iterative(str);

    return 0;
}