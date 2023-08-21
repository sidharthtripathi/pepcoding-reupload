// https://practice.geeksforgeeks.org/problems/topological-sort/1

class Solution
{
	public:
	void DFS(vector<int> adj[],vector<bool> &visited , stack<int> &s , int src){
	    visited[src] = true;
	   
	    // goint to the nbrs
	    vector <int> nbrs = adj[src];
	    for(int i = 0 ; i<nbrs.size() ; i++){
	        if(visited[nbrs[i]] == false){
	            DFS(adj,visited,s,nbrs[i]);
	        }
	    }
	    
	    // after coming out
	    s.push(src);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool> visited(V,false);
	    stack<int> s;
	    
	    for(int i = 0 ; i<V ; i++){
	        if(visited[i] == false){
	            DFS(adj,visited,s,i);
	        }
	    }
	    
	    // taking out the stack elements
	    vector<int> ans;
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    
	    return ans;
	}
};