class Solution {
  public:
    // Function to find the number of islands.
    
    void DFS(vector <vector<char>> &grid , vector <vector <bool>> &visited , pair<int,int> src){
        // marking as visited
        int r = src.first;
        int c = src.second;
        visited[r][c] = true;
        
        // visiting over its nbrs
        
        for(int i = -1 ; i<= 1 ; i++){
            for(int j = -1 ; j<=1 ; j++){
              int nr = r + i;
              int nc = c + j;
              if(nr>=0 and nr<grid.size()  and nc>=0 and nc<grid[0].size() and grid[nr][nc] == '1' and visited[nr][nc] == false){
                  DFS(grid,visited,{nr,nc});
              }
              
            }
        }
        
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        // creating a visited matrix
        vector<vector<bool>> visited;
        for(int i = 0 ; i<grid.size() ; i++){
            vector <bool> temp(grid[i].size(),false);
            visited.push_back(temp);
        }
        
        // travelling to each index
        int count = 0;
        for(int i = 0 ; i<grid.size() ; i++){
            for(int j = 0 ; j<grid[0].size() ; j++){
                if(grid[i][j]== '1' and visited[i][j]==false ){
                    count++;
                    DFS(grid,visited,{i,j});
                   
                    
                }
            }
            
        }
        
        return count;
    }
};

// Link
// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands