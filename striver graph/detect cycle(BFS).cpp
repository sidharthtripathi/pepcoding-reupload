class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cyclicHelper(vector<int> adj[] , vector <bool> &visited , int src){
        visited[src] = true;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            // adding his buddies which are not visited
            for(auto adjNode : adj[node]){
                if(visited[adjNode] == false){
                    visited[adjNode] = true;
                    q.push({adjNode,node});
                }
                else if(adjNode != parent){
                    return true;
                }
            }
        }
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,false);
        for(int i = 0 ; i<V; i++){
            if(visited[i] == false){
            if(cyclicHelper(adj,visited,i)){
                return true;
            }
            }
        }
        return false;
        
    }
};