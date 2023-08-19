class Solution {
public:

    void DFS(vector <vector<bool>> &visited , int sr , int sc , vector <vector<int>> &tempImage , int oriC , int newC){
        if(tempImage[sr][sc] == oriC){
            tempImage[sr][sc] = newC;
            visited[sr][sc] = true;
        }
        
        // calling its buddies now
        // buddies should be of original color
        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};
        
        for(int i = 0 ; i<4 ; i++){
            int r = sr + delr[i];
            int c = sc + delc[i];
            if(r>=0 and r<tempImage.size() and c>=0 and c<tempImage[0].size() and visited[r][c] == false and tempImage[r][c] == oriC)
            DFS(visited,r,c,tempImage,oriC,newC);
        }
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector <bool> tempFill(image[0].size(),false);
        vector <vector <bool>> visited(image.size(),tempFill);
        vector < vector <int>> tempImg = image;
        int oriC = image[sr][sc];
        DFS(visited,sr,sc,tempImg,oriC,newColor);
        return tempImg;
        
        
        
    }
};

// Link
// https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1