class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool DFS(int src, int parent, vector<int> adj[] , vector<int> &visited , vector<int> &visitedPath){
        // setting the path and visited
        visited[src] = true;
        visitedPath[src] = true;
        
        // visiting to all its nbrs
        
        vector <int> nbrs = adj[src];
        for(int i = 0 ; i<nbrs.size() ; i++){
            if(visited[nbrs[i]] == false){
                if(DFS(nbrs[i],src,adj,visited,visitedPath))
                    return true;
            }
            
            else {
                if(visitedPath[nbrs[i]] == true)
                    return true;
            }
        }
        
        // unmark when you go back
        visitedPath[src] = false;
        return false;
        
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V,false);
        vector<int> visitedPath(V,false);
        
        for(int i = 0 ; i<V ; i++){
            if(visited[i] == false)
                if(DFS(i,-1,adj,visited,visitedPath))
                return true;
        }
        
        return false;
    }
};


// link
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1