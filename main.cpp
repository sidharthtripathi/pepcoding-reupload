#include <iostream>
using namespace std;
#include <vector>

vector <vector<int>> createGraph(int v , vector < pair<int,int> > edges){

vector < vector < int > > graph;
// filling the graph with empty
for(int i = 0 ; i<v ; i++){
    vector <int> temp;
    graph.push_back(temp);
}

// making the graph
for(int i = 0 ; i<edges.size() ; i++){
   int src = edges[i].first;
   int dest = edges[i].second;
   graph[src].push_back(dest);
}

return graph;

}

int main(){

}