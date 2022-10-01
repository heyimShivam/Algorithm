#include <iostream>
#include <array>

using namespace std;

int lsearch(int arr[], int n, int l)//n represents the numebr to be searched, l is the length of the array
{
    for(int i=0;i<l;i++)
    {
        if(arr[i]==n)
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = {5,3,7,1,9,4,6,8};
    int n=1;
    int l=int(sizeof(arr)/sizeof(arr[0]));
    int res = lsearch(arr,n,l);
    if(res==-1)
        cout << "Element is not in the array" << endl;
    else
        cout << "Element is found in the position " << res+1 << endl;
    return 0;
}
