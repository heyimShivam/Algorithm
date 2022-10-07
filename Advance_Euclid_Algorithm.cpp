#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define si stack<int>
#define ll long long
#define rep(i,a,b) for(int i=a; i<b; i++)
const int N = 1e5+2, MOD = 1e9+7;
// ax + by = gcd(a,b)
// gcd(d,0) = d

struct triplet
{
  int x,y,gcd;
};

triplet ExtendedEuclid(int a, int b){
  //Base Case 
  if(b==0){
    triplet ans;
    ans.x = 1;    //As, ax + 0 = a  //And y==0
    ans.gcd = a;
    ans.y = 0;
    return ans;
  }

  triplet smallAns = ExtendedEuclid(b,a%b);
  triplet ans;
  ans.gcd = smallAns.gcd;
  ans.x = smallAns.y;
  ans.x = smallAns.x - (a/b)*smallAns.y;
  return ans;
}

int main()
{
  int a,b;
  cin>>a>>b;

  triplet ans = ExtendedEuclid(a,b);
  cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<endl;

  return 0;
}