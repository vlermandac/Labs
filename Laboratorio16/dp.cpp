#include<vector>
#include<string>
using namespace std;

class Solution1{
public:
    vector<vector<int>> dp;

    int minDistance(string word1, string word2) {
        dp.assign(word1.size(), vector<int>(word2.size(), -1));
        return solve(0, 0, word1, word2);
    }
    int solve(int i, int j, const string &word1, const string &word2) {
        if (i >= word1.size() || j >= word2.size())
            return (word2.size() - j) + (word1.size() - i);
        if(i == word1.size()) return word2.size() - j;
        if(j == word2.size()) return word1.size() - i;

        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j])
            return dp[i][j] = solve(i+1, j+1, word1, word2);

        int insert = 1 + solve(i, j+1, word1, word2);
        int dlete = 1 + solve(i+1, j, word1, word2);
        int replace = 1 + solve(i+1, j+1, word1, word2);

        return dp[i][j] = min(min(insert, dlete), replace);
    }
};

class Solution2{
public:
  int minDistance(string word1, string word2) {
      int m = word1.size();
      int n = word2.size();
      int dp[m+1][n+1];
      for(int i = 0; i <= m; i++) dp[i][0] = i;
      for(int j=0; j <= n; j++) dp[0][j] = j;
      
      for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
          if(word1[i-1] == word2[j-1])
            dp[i][j] = dp[i-1][j-1];
          else{
            dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
          }
        }
    return dp[m][n];
  }

};
