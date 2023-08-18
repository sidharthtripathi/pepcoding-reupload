#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int sW = INT_MAX;
int lW = INT_MIN;
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



void multiSolver(vector<vector<Edge>> graph,int s, int d , vector <int> psf ,int wsf, vector<bool> visited){

    visited[s] = true;

    if(s==d){
        if(wsf < sW){
            sW = wsf;
            sp = psf;
        }
        if(wsf > lW){
            lW = wsf;
            lp = psf; 
        }

        return;
    }

    

    for(int i = 0 ; i<graph[s].size() ; i++){
        if(visited[graph[s][i].n]==false){
            psf.push_back(graph[s][i].n);
            wsf = wsf + graph[s][i].wt;
            multiSolver(graph,graph[s][i].n,d,psf,wsf,visited);
            wsf = wsf - graph[s][i].wt;
            psf.pop_back();
        }
    }

    visited[s] = false;



}

int main(){
   vector <vector<Edge>> graph = createGraph(7,8);
   int s; cin>>s;
   int d; cin>>d;
   vector <bool> visited(7,false);
   vector<int> psf;
   int wsf = 0;
   psf.push_back(s);
    multiSolver(graph,s,d,psf,wsf,visited);

    cout<<sW<<" @ ";
    printArr(sp);
    cout<<lW<<" @ ";
    printArr(lp);
    
    
  

}