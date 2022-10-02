#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};

const int N = 100010;
struct Point {
    double x,y;
} p[N];
int n,tmp_p[N];
bool cmpx(Point a , Point b) {
    if (a.x < b.x)  return true;
    else            return false;
}
bool cmpy(int a, int b) {
    if(p[a].y < p[b].y) return true;
    else                return false;
}
double dis(int i, int j) {
    return sqrt((p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y));
}
double Closest_Pair(int l, int r) {
    if (l == r) return 1e18;
    if (l + 1 == r) return dis(l, r);

    int mid = (l + r)/2,k = 0;
    double mindis = min(Closest_Pair(l, mid),Closest_Pair(mid+1, r));

	for (int i = l; i <= r; i++) {
        if (fabs(p[mid].x - p[i].x) <= mindis)
            tmp_p[k++] = i;
    }

    sort(tmp_p, tmp_p + k, cmpy);
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k && p[tmp_p[j]].y - p[tmp_p[i]].y < mindis;j++) {
            double now = dis(tmp_p[i], tmp_p[j]);
            if (mindis-now > 1e-9) mindis = now;
        }
    }
    return mindis;
}
int main(){
	int n;
	cout << "Number of points: ";
	cin >> n;
	for(int i=0;i<n;i++){
		cout << "Coordinate of points " << i << ": ";
		cin >> p[i].x >> p[i].y;
	}
	sort(p,p+n,cmpx);	
	cout << "Minimum distance among the points: " << Closest_Pair(0,n-1);
}