#include<iostream>
using namespace std;

int main(){
    int a,n;
    cin>>a>>n;
    cout<<n<<"th bit of "<<a<<" is "<<(a&(1<<n))<<endl;
}
