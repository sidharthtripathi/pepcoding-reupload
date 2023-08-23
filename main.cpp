
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maxOfThree(int &a , int &b, int &c){
    if(a>b and a>c) return a;
    else if(b>a and b>c) return b;
    else if(c>a and c>b) return c;
    else return a;

}

// int answer(int sr, int sc, vector<vector<int>> &matrix,vector<vector<int>> &dp){

//     // base case
//     if(sr == matrix.size()-1){
//         int maxi = INT_MIN;
//         for(int i = 0 ; i<matrix[sr].size() ; i++){
//             maxi = max(maxi,matrix[sr][i]);
//         }
//         return maxi;
//     }

//     // check if we got the ans
//     if(dp[sr][sc] != -1) return dp[sr][sc];
     
//      // picking from row and moving forward
//      int maxD = INT_MIN/2, maxDL = INT_MIN/2, maxDR = INT_MIN/2;
//      for(int i = 0 ; matrix[sr].size() ; i++){
//          // valid down movement
//          if(sr+1<matrix.size()-1){
//              int result = answer(sr+1,sc,matrix,dp) + matrix[sr][i];
//              maxD = max(maxD,result);
//          }
//          // valid down left movement
//          if(sr+1<matrix.size()-1 and sc>0){
//              int result = answer(sr+1,sc-1,matrix,dp) + matrix[sr][i];
//              maxDL = max(maxDL,result);
//          }

//          // valid down right movement
//          if(sr+1<matrix.size()-1 and sc<matrix[sr+1].size()-1){
//              int result = answer(sr+1,sc+1,matrix,dp) + matrix[sr][i];
//              maxD = max(maxD,result);
//          }
//      }

//      int ans =  maxOfThree(maxD,maxDL,maxDR);
//      dp[sr][sc] = ans;
//      return ans;


// }






int answer(int sr, int sc, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    // base case
    if (sr == matrix.size() - 1) {
        int maxi = INT_MIN;
        for (int i = 0; i < matrix[sr].size(); i++) {
            maxi = max(maxi, matrix[sr][i]);
        }
        return maxi;
    }

    // check if we got the ans
    if (dp[sr][sc] != -1) return dp[sr][sc];

    // Initialize maxD, maxDL, and maxDR
    int maxD = INT_MIN / 2, maxDL = INT_MIN / 2, maxDR = INT_MIN / 2;

    for (int i = 0; i < matrix[sr].size(); i++) { // Corrected loop condition
        // valid down movement
        if (sr + 1 < matrix.size()) {
            int result = answer(sr + 1, sc, matrix, dp) + matrix[sr][i];
            maxD = max(maxD, result);
        }
        // valid down left movement
        if (sr + 1 < matrix.size() && sc > 0) {
            int result = answer(sr + 1, sc - 1, matrix, dp) + matrix[sr][i];
            maxDL = max(maxDL, result);
        }
        // valid down right movement
        if (sr + 1 < matrix.size() && sc < matrix[sr + 1].size() - 1) {
            int result = answer(sr + 1, sc + 1, matrix, dp) + matrix[sr][i];
            maxDR = max(maxDR, result);
        }
    }

    int ans = maxOfThree(maxD, maxDL, maxDR);
    dp[sr][sc] = ans;
    return ans;
}










int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
    return answer(0,0,matrix,dp);
    
}

int main(){
   vector<vector<int>> matrix;
   int rows;cin>>rows;
   int cols; cin>>cols;
   for(int i = 0 ; i<rows; i++){
      vector<int> tempArr;
      for(int j = 0 ; j<cols ; j++){
         int temp; cin>>temp;
         tempArr.push_back(temp);
       }
       matrix.push_back(tempArr);
   }


   cout<<getMaxPathSum(matrix);
}