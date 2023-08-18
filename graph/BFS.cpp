#include <iostream>
#include <vector>
#include <queue>
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

class Ds{
public:
    int s;
    vector <int> path;
    Ds(int s , vector<int> path){
        this->s = s;
        this->path =  path;
    }
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

void BFS(vector <vector<Edge>> graph, int v, int s){
    queue<int> q;
    vector<bool> visited(v,false);
    q.push(s);
    visited[s] = true;

    while(q.empty()==false){
        // print the item
        cout<<q.front()<<" ";
        // add the neighbours
        for(int i = 0 ; i<graph[q.front()].size() ; i++){
            if(visited[graph[q.front()][i].n] == false){
                q.push(graph[q.front()][i].n);
                visited[graph[q.front()][i].n] = true;
            }
            
        }
        q.pop();
    }


}




int main(){
    int v; cin>>v;
    int e; cin>>e;
   vector <vector<Edge>> graph = createGraph(v,e);
   vector <bool> visited(v,false);
   int s; cin>>s;
   BFS(graph,v,s);
   

   


}