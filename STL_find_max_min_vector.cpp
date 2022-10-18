#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> point;
    point.push_back(0);
    point.push_back(1);
    point.push_back(3);
    for(int i=0;i<point.size();i++){
        cout<<point[i]<<" ";
    }cout<<endl;
int maxi=point[0],mini=point[0];
for(int i=0;i<point.size();i++){
        maxi=max(maxi,point[i]);
    mini=min(point[0],point[i]);
    }

cout<<"Maximum= "<<maxi<<endl;
cout<<"Minimum= "<<mini<<endl;
    return 0;
}
