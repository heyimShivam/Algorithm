#include <iostream>
using namespace std;
int numberSquare(int n){
    int ans=0;
    while(n>0){
      int rem = n%10;
      ans+= (rem*rem);
      n = n/10;
    }
    return ans;
}
bool isHappy(int n){
    int f = n;
    int s = n;
    do{
       f = numberSquare(f);
       s = numberSquare(numberSquare(s)); 
    }while(f!=s);
    if(f==1){
        return true;
    }
   
       return  false;
    
}
int main()
{
   int n ;
   cin>>n;
   if(isHappy(n)){
   cout<<"Yes it is a happy number";}
   else{
       cout<<"No, it is not";} 
   

   
}
