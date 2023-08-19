class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector <bool> visited(V,false);
        vector <int> psf;
        psf.push_back(0);
        visited[0] = true;
        int src = 0;
        traversal(adj,src,visited,psf);
        return psf;
        
    }
    
    void traversal(vector <int> adj[] , int src,vector <bool> &visited , vector <int> &psf){
        visited[src] = true;
        // iterating over the nbr
        
        for(int i = 0 ; i<adj[src].size() ; i++){
            int nbr = adj[src][i];
            if(visited[nbr] == false){
                psf.push_back(nbr);
                visited[nbr] = true;
                traversal(adj,nbr,visited,psf);
                //psf.pop_back();
            }
            
        }
        
    }
};

// Link
// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1