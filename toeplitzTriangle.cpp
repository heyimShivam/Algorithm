#include<iostream>
using namespace std;
void SetData(int a[],int n,int i,int j,int x){
    if(i<=j){
        a[j-i]=x;
    }
    else{
        a[n+(i-j)]=x;
    }
    
    
}
void display(int a[],int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
        if(i<=j){
        cout<<a[j-i]<<" ";
    }
    else{
      cout<<a[n+(i-j)]<<" ";
    }
        }
        cout<<endl;
    }
}
int main(){
    int a[9];
    SetData(a,5,1,1,1);
     SetData(a,5,1,2,2);
      SetData(a,5,1,3,3);
       SetData(a,5,1,4,4);
     SetData(a,5,1,5,5);   
     SetData(a,5,2,1,6);
      SetData(a,5,3,1,7);
       SetData(a,5,4,1,8);
        SetData(a,5,5,1,9);
        display(a,5);
}
