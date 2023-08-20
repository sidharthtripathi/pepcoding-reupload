// https://practice.geeksforgeeks.org/problems/bipartite-graph/1

class Solution {
public:
   bool isBipartite(int V, vector<int>adj[]){
     vector <int> colors(V,-1);
     for(int i = 0 ; i<V ; i++){
         if(colors[i] == -1){
         if(DFS(adj,colors,i) == false)
            return false;
         }
     }

      return true; 
   }

   bool DFS(vector<int> adj[] ,vector<int> &colors, int src , int parent = -1 ){
      if(parent==-1) colors[src] = 0;
      else colors[src] = !colors[parent];

      // visiting nbrs
      vector <int> nbrs = adj[src];
      for(int i = 0 ; i<nbrs.size() ; i++){
         if(colors[nbrs[i]] == -1){
            if(DFS(adj,colors,nbrs[i],src) == false){
               return false;
            }
         }
         else{
            if(colors[nbrs[i]] == colors[src])
               return false;
         }
      } 


      return true;


   }

  

};