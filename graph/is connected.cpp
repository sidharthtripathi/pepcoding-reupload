#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int ciel = INT_MAX;
int flr = INT_MIN;
int val = INT_MIN;
vector <int> sp;
vector <int> lp;


void printArr(vector <int> &a){
    for(int i = 0 ; i<a.size() ; i++)
        cout<<a[i]<<" ";
    cout<<endl;
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



void components(vector<vector<Edge>> graph,int s, vector <int> &psf ,vector<bool> &visited){
    visited[s] = true;
    psf.push_back(s);
    for(int i = 0 ; i<graph[s].size() ; i++){
        if(visited[graph[s][i].n] == false){
            components(graph,graph[s][i].n , psf , visited);
        }
    }

}

int main(){
    int v = 7;
    int e = 5;
   vector <vector<Edge>> graph = createGraph(v,e);
   vector <bool> visited(v,false);
   vector <vector<int>> ans;
   for(int i = 0 ; i<v ; i++){
    if(visited[i]==false){
        vector <int> comp;
        components(graph,i,comp,visited);
        ans.push_back(comp);
    }
   }

  // if only one component, then connected
   if(ans.size()==1)
    cout<<"connected";
    else
        cout<<"not connected";

}