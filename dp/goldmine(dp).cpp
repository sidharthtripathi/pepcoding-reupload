#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int maxOfThree(int a , int b , int c){
   if(a>b and a>c) return a;
   else if(b>a and b>c) return b;
   else if(c>a and c>b) return c;
   return a;

}

int travel(int sr, int sc, vector<vector<int>> &grid , vector<vector<int>> &dp){
   if(sc == grid[0].size()-1){
      return grid[sr][sc];
   }
   cout<<"calling.."<<endl;

   // dp array
   if(dp[sr][sc] != -1)
      return dp[sr][sc];

   // valid forward single step movement
   int maxF = INT_MIN;
   if(sc<grid[0].size()-1){
      maxF = travel(sr,sc+1,grid,dp);
   }

   // valid top right single step movement
   int maxUF = INT_MIN;
   if(sc<grid[0].size()-1 and sr>0){
      maxUF = travel(sr-1,sc+1,grid,dp);
   }

   // valid top down single step movement
   int maxDF = INT_MIN;
      if(sc<grid[0].size()-1 and sr<grid.size()-1){
      maxDF = travel(sr+1,sc+1,grid,dp);
   }

   int ans = maxOfThree(maxF,maxDF,maxUF) + grid[sr][sc];
   dp[sr][sc] = ans;
   return ans;

}

int ansEvaluate(vector<vector<int>> &grid,vector<vector<int>> &dp){


   // travelling across all the row
   int maxi = INT_MIN;
   for(int i = 0 ; i<grid.size() ; i++){
      int golmineSum = travel(i,0,grid,dp);
      maxi = max(maxi,golmineSum);
   }
   return maxi;

}



int main(){
   // create the grid
   int rows; cin>>rows;
   int cols; cin>>cols;
   vector<vector<int>> grid;
   // vector<vector<int>> dp(rows,vector<int>(cols,-1));
   // filling grid
   for(int i =0 ; i<rows ; i++){
      vector<int> tempArr;
      for(int j = 0 ; j<cols ; j++){
         int temp; cin>>temp;
         tempArr.push_back(temp);
      }
      grid.push_back(tempArr);
   }

   // creating dp array
   vector<vector<int>> dp(rows,vector<int>(cols,-1));

   cout<<ansEvaluate(grid,dp);
   
   
}