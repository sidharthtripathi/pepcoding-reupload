#include <iostream>
#include <vector>
#include <climits>
using namespace std;


void printArr(vector <int> &a){
    for(int i = 0 ; i<a.size() ; i++)
        cout<<a[i]<<" ";
}

class Edge{
public:
    int s = 0;
    int n = 0;
    int wt = 0;
    Edge(int s , int n , int wt){
        this->s = s;
        this->n = n;
        this->wt = wt;
    }
    Edge(){}
};

// creating our graph normally

vector <vector<Edge>> createGraph(int vertices , int edges){
    vector <vector<Edge>> graph;
    for(int i = 0 ; i<vertices ;i++){
        vector <Edge> temp;
        graph.push_back(temp);
    }

    for(int i = 0 ; i<edges ; i++){
        int s; cin>>s;
        int d; cin>>d;
        int wt; cin>>wt;
        Edge e(s,d,wt);
        Edge e2(d,s,wt);
        graph[s].push_back(e);
        graph[d].push_back(e2);
    }

return graph;
    
}

bool allVisited(vector<bool> &visited){
    for(int i = 0 ; i<visited.size() ; i++){
        if(visited[i]==false)
        return false;
    }
    return true;
}

void HamiltonianPandC(vector <vector<Edge>> &graph,int s , vector<int> &psf , vector <bool> &visited , int oriS){
    visited[s] = true;
    // base case
    // all the vertices are visited
    if(allVisited(visited)){
    // all visited thus print the path
    printArr(psf);
    int cycle = false;
    // checking if hamiltonian path or cycle
    for(int i = 0 ; i<graph[s].size() ; i++){
        if(graph[s][i].n == oriS){
            cycle = true;
            cout<<"*"<<endl;
            break;
        }
    }
    if(cycle==false)
        cout<<"."<<endl;

    visited[s] = false;
    return;
    }


    for(int i = 0 ; i<graph[s].size() ; i++){
        if(visited[graph[s][i].n] == false){
            psf.push_back(graph[s][i].n);
            HamiltonianPandC(graph,graph[s][i].n,psf,visited,oriS);
            psf.pop_back();
        }
    }

    visited[s] = false;


}

int main(){
    int v; cin>>v;
    int e; cin>>e;
   vector <vector<Edge>> graph = createGraph(v,e);
   vector <bool> visited(v,false);
   int s; cin>>s;
   vector<int> psf;
   psf.push_back(s);
   HamiltonianPandC(graph,s,psf,visited,s );


}