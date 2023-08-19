class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector <bool> visited(V,false);
        vector <int> result;
        queue<int>q;
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
            int current = q.front();
            result.push_back(q.front());
            q.pop();
            // adding its neighbours
            for(int i = 0 ; i<adj[current].size() ; i++){
                if(visited[adj[current][i]] == false){
                    q.push(adj[current][i]);
                    visited[adj[current][i]] = true;
                }
            }
            
                
            
        }
    
        return result;
    }
    
};


// Link to question
// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1