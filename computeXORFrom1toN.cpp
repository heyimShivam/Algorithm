#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    if((n&3)==3){
        cout<<"0"<<endl;
    }
    else if((n&2)==2){
        cout<<n+1<<endl;
    }
    else if(n&1){
        cout<<"1"<<endl;;
    }
    else{
        cout<<n<<endl;;
    }
}
