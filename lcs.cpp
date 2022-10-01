//Bottom up approach
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int lcs(string pattern_1, string pattern_2, int len_1, int len_2) {
  if (len_1 == 0 || len_2 == 0)
    return 0;
  if (pattern_1[len_1 - 1] == pattern_2[len_2 - 1]) {
    return 1 + lcs(pattern_1, pattern_2, len_1 - 1, len_2 - 1);
  } else {
    return max(lcs(pattern_1, pattern_2, len_1 - 1, len_2), lcs(pattern_1, pattern_2, len_1, len_2 - 1));
  }
}
int main() {
  string pattern_1, pattern_2;
  pattern_1 = "RGBGARGA";
  pattern_2 = "BGRARG";
  cout<<"Length of LCS is: "<<lcs(pattern_1, pattern_2, pattern_1.size(), pattern_2.size())<<endl;
}

//Top down approach
#include <bits/stdc++.h>
using namespace std;


const int max_value = 1000;


int N, M;

int lcs(string S, string T, int i, int j, int memo[][max_value])
{

    if (i == N || j == M)
        return 0;


    if (memo[i][j] != -1)
        return memo[i][j];

    if (S[i] == T[j])

        memo[i][j] = lcs(S, T, i + 1, j + 1, memo) + 1;
    else

        memo[i][j] = max(lcs(S, T, i + 1, j, memo), lcs(S, T, i, j + 1, memo));
    return memo[i][j];
}

int main()
{
    string S = "abcde";
    string T = "acek";

    N = S.length();
    M = T.length();

    int memo[N][max_value];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            memo[i][j] = -1;


    cout << "Length of longest common subsequence " << lcs(S, T, 0, 0, memo);
    return 0;
}
