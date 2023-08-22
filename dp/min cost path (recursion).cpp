#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int minCostPath(vector<vector<int>> &grid, int sr , int sc){

   if(sr == grid.size()-1 and sc == grid[0].size()-1){
      return grid[grid.size()-1][grid[0].size()-1];
   }

   // valid horizontal move
   int minH = INT_MAX;
   if(sc+1<grid[0].size()){
      minH = 0;
      minH = minCostPath(grid,sr,sc+1);
      minH = minH + grid[sr][sc];
   }
   

   // valid vertical move
   int minV = INT_MAX;
   if(sr+1<grid.size()){
      minV = 0;
      minV = minCostPath(grid,sr+1,sc);
      minV = minV + grid[sr][sc];
   }
   
   int ans = min(minH,minV);
   dp[sr][sc] = ans;
   return ans;

}



int main(){
   // create the grid
   int rows; cin>>rows;
   int cols; cin>>cols;
   vector<vector<int>> grid;
   for(int i =0 ; i<rows ; i++){
      vector<int> tempArr;
      for(int j = 0 ; j<cols ; j++){
         int temp; cin>>temp;
         tempArr.push_back(temp);
      }
      grid.push_back(tempArr);
   }
   cout<<minCostPath(grid,0,0);
   
   
}