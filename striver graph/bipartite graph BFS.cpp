// https://practice.geeksforgeeks.org/problems/bipartite-graph/1
class Solution {
public:
   bool isBipartite(int V, vector<int>adj[]){
      vector <int> colors(V,-1);
      for(int i = 0 ; i<V ; i++){
         if(colors[i] == -1){
            if(checkComponent(adj,i,colors) == false)
               return false;

         }
      }
      return true;
   }

   bool checkComponent(vector<int>adj[] ,int src,vector<int> &colors){
             // Code here
      // -1 not visited ( not colored ), 1 => color 1 , 0 => color 0
      queue<int> q;
      q.push(src);
      colors[src] = 0;

      while(!q.empty()){
         int node = q.front();
         q.pop();
         // going to his nbrs
         vector<int> nbrs = adj[node];
         for(int i = 0 ; i<nbrs.size() ; i++){
            if(colors[nbrs[i]] == -1){
               q.push(nbrs[i]);
               colors[nbrs[i]] = !colors[node];
            }
            else{
               if(colors[nbrs[i]] == colors[node])
                  return false;
            }
         }
      }
      return true;
   }

};