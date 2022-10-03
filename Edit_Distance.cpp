/*
    link: https://leetcode.com/problems/edit-distance/
    TC: O(nm)
    SC: O(m)
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(2, vector<int>(m+1));
        
        for(int j=0; j<m+1; j++)dp[n%2][j] = m-j;
        
        for(int i=n-1; i>=0; i--){
            dp[i%2][m] = n-i;
            for(int j=m-1; j>=0; j--){
                int index = i%2, nxtIndex = (i+1)%2;
                
                if(word1[i] == word2[j])dp[index][j] = dp[nxtIndex][j+1];
                else dp[index][j] = INT_MAX;
                
                dp[index][j] = min({dp[nxtIndex][j]+1, dp[index][j+1] + 1, dp[nxtIndex][j+1]+1, dp[index][j]});
            }
        }
        
        return dp[0][0];
    }
};
