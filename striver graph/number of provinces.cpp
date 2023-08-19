class Solution {
  public:
    void DFS(vector <vector <int>> &adj , vector <bool> &visited , int src){
        visited[src] = true;
        
        for(int i = 0 ; i<adj[src].size() ; i++){
            int nbr = adj[src][i];
            if(visited[nbr] == false){
                DFS(adj,visited,nbr);
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adjM, int V) {
        // code here
        // converting adj matrix to list
        vector <vector<int>> adj;
        for(int i = 0 ; i<V ; i++){
            vector<int> temp;
            adj.push_back(temp);
        }
        
        for(int i = 0 ; i<adjM.size() ; i++){
            // check all places where j is 1
            for(int j = 0 ; j<adjM[i].size() ; j++){
                if(adjM[i][j] == 1 and i!=j){
                    adj[i].push_back(j);
                }
            }
            
        }
        
        
        
        vector <bool> visited(V,false);
        int count = 0;
        for(int i = 0 ; i<V ; i++){
            if(visited[i] == false){
                count++;
                DFS(adj,visited,i);
            }
        }
        return count;
    }
};


// Link
// https://practice.geeksforgeeks.org/problems/number-of-provinces/1    