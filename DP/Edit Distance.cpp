// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

//     Insert a character
//     Delete a character
//     Replace a character

class Solution {
    int dp[501][501];
    int rec(string &word1,string &word2,int id1,int id2){
        if(id1>=word1.length()){
            return word2.size()-id2;
        }
        if(id2>=word2.length()){
            return word1.size()-id1;
        }
        
        if(word1[id1]==word2[id2]){
            return rec(word1,word2,id1+1,id2+1);
        }
        
        if(dp[id1][id2]!=-1){
            return dp[id1][id2];
        }
        
        int op1 = 0,op2 = 0,op3 = 0;
        op1 = 1 + rec(word1,word2,id1+1,id2+1); /// replace
        op2 = 1 + rec(word1,word2,id1+1,id2); /// insert
        op3 = 1 + rec(word1,word2,id1,id2+1); /// delete
        
        return dp[id1][id2] = min({op1,op2,op3});
    }
public:
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return rec(word1,word2,0,0);
    }
};
