#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 20;
    int b = 10;
    swap(a,b);
    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}