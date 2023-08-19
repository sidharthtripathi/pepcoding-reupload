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

bool isCycle(vector<vector<Edge>> graph, int v , int s){
    queue <pair<int,int>> q;
    vector<bool> added(v,false);
    q.push({s,-1});
    added[s] = true;

    while(!q.empty()){
        int current = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(int i = 0 ; i<graph[current].size() ; i++){
            if(added[graph[current][i].n] == false){
                q.push({graph[current][i].n,current});
                added[graph[current][i].n] = true;
            }
            else if(graph[current][i].n != parent)
                return true;
        }

    }
    return false;


}


int main(){
    int v; cin>>v;
    int e; cin>>e;
   vector <vector<Edge>> graph = createGraph(v,e);
   int s; cin>>s;
   bool ans = isCycle(graph,v,s);
   cout<<ans;

}