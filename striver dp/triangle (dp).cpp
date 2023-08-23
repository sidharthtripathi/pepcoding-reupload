#include <bits/stdc++.h> 
int answer(int sr, int sc , vector<vector<int>> triangle,vector<vector<int>> &dp){
   if(sr == triangle.size()-1){
      return triangle[sr][sc];
   }

   // check if we already got the answer
   if(dp[sr][sc]!=-1) return dp[sr][sc];
   

   // valid down movement
   int minDown = INT_MAX/2;
   if(sr<triangle.size()-1){
      minDown = answer(sr+1,sc,triangle,dp);
   }

   // valid diagonal down movement

   int minVDdia = INT_MAX/2;
   if(sr<triangle.size()-1 and sc<triangle[sr+1].size()-1){
      minVDdia = answer(sr+1,sc+1,triangle,dp);
   }
   dp[sr][sc] = triangle[sr][sc]+minDown <= triangle[sr][sc]+minVDdia ? triangle[sr][sc]+minDown : triangle[sr][sc]+minVDdia;
   return dp[sr][sc];
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
   // Write your code here.
   vector<vector<int>> dp(n,vector<int>(n,-1));
   return answer(0,0,triangle,dp);
}