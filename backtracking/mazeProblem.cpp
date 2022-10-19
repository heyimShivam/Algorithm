#include <bits/stdc++.h>
#include <iostream>
#include<string.h>
using namespace std;
int countPaths(int r,int c){
    if(r==1 || c==1){
        return 1;
    }
    int count=0;
    if(r>1){
        count =  count+ countPaths(r-1,c);
    }
    if(c>1){
         count =  count+ countPaths(r-1,c);
    }
    return count;
}

void PrintPaths(string pr,int r,int c){
    if(r==1 && c==1){
        cout<<pr<<endl;
        return;
        
    }
    
    if(r>1){
       PrintPaths("D"+pr,r-1,c);
    }
    if(c>1){
         PrintPaths("R"+pr,r,c-1);
    }
   
}



void PrintPathsDiagnol(string pr,int r,int c){
    if(r==1 && c==1){
        cout<<pr<<endl;
        return;
        
    }
    if(r>1 && c>1){
       PrintPathsDiagnol("d"+pr,r-1,c-1) ;
    }
    if(r>1){
       PrintPathsDiagnol("D"+pr,r-1,c);
    }
    if(c>1){
       PrintPathsDiagnol("R"+pr,r,c-1);
    }
   
}
void PrintPathsWithObstacle(string pr,int r,int c,vector<vector<bool>>&maze,int n){
    if(r==n-1 && c==n-1){
        cout<<pr<<endl;
        return;
        
    }
    if(!maze[r][c]){
        return;
    }
   
    if(r<n-1){
      PrintPathsWithObstacle("D"+pr,r+1,c,maze,n);
    }
    if(c<n-1){
       PrintPathsWithObstacle("R"+pr,r,c+1,maze,n);
    }
   
}
//Backtracking :  During every recursion we do some changes and after its completion we revert back the changes
void PrintPathsWithFourDir(string pr,int r,int c,vector<vector<bool>>&maze,int n){
    if(r==n-1 && c==n-1){
        cout<<pr<<endl;
        return;
        
    }
    if(!maze[r][c]){
        return;
    }
   maze[r][c]=false;
    if(r<n-1){
     PrintPathsWithFourDir("D"+pr,r+1,c,maze,n);
    }
    if(c<n-1){
       PrintPathsWithFourDir("R"+pr,r,c+1,maze,n);
    }
    if(c>0){
       PrintPathsWithFourDir("L"+pr,r,c-1,maze,n);
    }
    if(r>0){
       PrintPathsWithFourDir("U"+pr,r-1,c,maze,n);
    }
    if(c<n-1 && r<n-1){
       PrintPathsWithFourDir("d"+pr,r+1,c+1,maze,n);
    }
   
   maze[r][c]=true;
}


int main()
{
    
//cout<<countPaths(3,3);
//PrintPaths("",3,3);
//PrintPathsDiagnol("",3,3);
vector<vector<bool>> maze = {{true,true,true},{true,true,true},{true,true,true}};
 PrintPathsWithFourDir("",0,0,maze,3);
    return 0;
}

