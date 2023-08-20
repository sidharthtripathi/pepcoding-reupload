class Solution{
    void DFS(vector<vector<bool>> &visited,vector <vector<char>> &mat , vector<vector<int>>& marked,int sr ,int sc){
        // we'll end up here only when our nbr or us were connected to boundary
        marked[sr][sc] = -1;
        visited[sr][sc] = true;
        
        // now visiting to his nbrs
        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};
        for(int i = 0 ; i<4 ; i++){
            int r = sr + delr[i];
            int c = sc + delc[i];
            if(r>=0 and r<mat.size() and c>=0 and c<mat[0].size() and visited[r][c] == false and mat[r][c] == 'O'){
                DFS(visited,mat,marked,r,c);
            }
    }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        vector<vector<int>> marked(n,vector<int>(m,0));
        
        // iterating over the edges of wall
        for(int i = 0 ; i<n  ; i++){
            for(int j = 0 ; j<m ; j++){
                if((i == 0 or i==n-1 or j==0 or j==m-1) and visited[i][j] == false and mat[i][j] == 'O'){
                    DFS(visited,mat,marked,i,j);
                }
            }
        }
        
        // now fixing the array
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(marked[i][j] != -1)
                    mat[i][j] = 'X';
            }
        }
        
        return mat;
        
        
    }
};


// link
// https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1