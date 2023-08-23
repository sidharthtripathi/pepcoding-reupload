#include <bits/stdc++.h> 
int answer(int sr, int sc , vector<vector<int>> triangle){
   if(sr == triangle.size()-1){
      return triangle[sr][sc];
   }

   // valid down movement
   int minDown = INT_MAX/2;
   if(sr<triangle.size()-1){
      minDown = answer(sr+1,sc,triangle);
   }

   // valid diagonal down movement

   int minVDdia = INT_MAX/2;
   if(sr<triangle.size()-1 and sc<triangle[sr+1].size()-1){
      minVDdia = answer(sr+1,sc+1,triangle);
   }
   return triangle[sr][sc]+minDown <= triangle[sr][sc]+minVDdia ? triangle[sr][sc]+minDown : triangle[sr][sc]+minVDdia;
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
   // Write your code here.
   return answer(0,0,triangle);
}