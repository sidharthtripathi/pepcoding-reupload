class Solution {
    void DFS(vector<vector<bool>> &visited , vector<vector<int>> &grid,vector<vector<int>> &marked, int sr, int sc){
        marked[sr][sc] = -1;
        visited[sr][sc] = true;
        
        // now exploring its nbrs
        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};
        
        for(int i = 0 ; i<4 ; i++){
            int r = sr + delr[i];
            int c = sc + delc[i];
            if(r>=0 and r<grid.size() and c>=0 and c<grid[0].size() and visited[r][c] == false and grid[r][c] == 1){
                DFS(visited,grid,marked,r,c);
            }
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        vector <vector<int>> marked(n,vector<int>(m,0));
        
        // travelling over the edges of wall
        for(int i = 0 ; i<grid.size() ; i++){
            for(int j = 0 ; j<grid[0].size() ; j++){
                if((i==0 or i==n-1 or j==0 or j==m-1) and grid[i][j]==1 and visited[i][j] == false){
                    DFS(visited,grid,marked,i,j);
                }
            }
        }
        
        // our marked will be set until here
        int count = 0 ;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j]==1 and marked[i][j] != -1)
                count++;
            }
        }
        return count;
        
        
    }
};


// Link
//https://practice.geeksforgeeks.org/problems/number-of-enclaves/1