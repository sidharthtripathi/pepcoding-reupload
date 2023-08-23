#include <bits/stdc++.h> 

int answer(int sr, int sc , vector<vector<int>> &grid){
    // base case
    if(sr == grid.size()-1 and sc == grid[0].size()-1){
        return grid[sr][sc];
    }

    // valid down movement
    int vMin = INT_MAX/2;
    if(sr<grid.size()-1){
        vMin = answer(sr+1 , sc , grid);
    }

    // valid right movement
    int hMin = INT_MAX/2;
    if(sc<grid[0].size()-1){
        hMin = answer(sr,sc+1,grid);
    }

    return vMin+grid[sr][sc] <= hMin+grid[sr][sc] ? vMin+grid[sr][sc] : hMin+grid[sr][sc];


}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    return answer(0,0,grid);
}