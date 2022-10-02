#include <iostream>
using namespace std;

void fun(int A [],int n){
    for(int i =0; i<n;i++){
        cout<<A[i]<<endl;
    }
    cout<<sizeof(int*)<<endl;
}

int main (){
    int A [] = {1,2,3,4,5};
    int n = sizeof(A)/sizeof(int);

    fun(A,n);
    cout<<n<<endl;
    for(int x:A)cout<<x<<" ";
}