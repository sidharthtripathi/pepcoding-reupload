class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{   int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> result(rows, vector<int>(cols, INT_MAX)); // Initialize result with maximum values.

        queue<pair<int, int>> q; // Use a single queue.
        
        // Initialize the queue with the positions of all 1s.
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    result[i][j] = 0; // Distance to a 1 is 0.
                }
            }
        }
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while (!q.empty()) {
            pair<int, int> cell = q.front();
            q.pop();
            
            int r = cell.first;
            int c = cell.second;
            
            // Visit neighbors of the current cell.
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                // Check if the neighbor is within bounds and if the distance can be reduced.
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && result[nr][nc] > result[r][c] + 1) {
                    result[nr][nc] = result[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        return result;
    }
	};

// Link
// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1