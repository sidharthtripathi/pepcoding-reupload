#include <iostream>
#include <vector>
using namespace std;

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
    // graph[0].push_back(*(new Edge(0,3,40)));
    // graph[0].push_back(*(new Edge(0,31,10)));

    // graph[1].push_back(*(new Edge(1,0,10)));
    // graph[1].push_back(*(new Edge(1,2,10)));

    // graph[2].push_back(*(new Edge(2,3,10)));
    // graph[2].push_back(*(new Edge(2,1,10)));

    // graph[3].push_back(*(new Edge(3,0,40)));
    // graph[3].push_back(*(new Edge(3,2,10)));
    // graph[3].push_back(*(new Edge(3,4,2)));

    // graph[4].push_back(*(new Edge(4,3,2)));
    // graph[4].push_back(*(new Edge(4,5,3)));
    // graph[4].push_back(*(new Edge(4,6,3)));

    // graph[5].push_back(*(new Edge(5,4,3)));
    // graph[5].push_back(*(new Edge(5,6,3)));

    // graph[6].push_back(*(new Edge(6,5,3)));
    // graph[6].push_back(*(new Edge(6,4,8)));

return graph;
    
}

bool hasPath(vector < vector<Edge> > &graph, int s, int d , vector <int> &marked){
    // check if we already came
    bool already = false;
    for(int i = 0 ; i<marked.size() ; i++){
        if(marked[i]==s){
            already = true;
            break;
        }
    }

    if(already == false){
        marked.push_back(s);
    }

    // base case
    if(s == d)
        return true;

    for(int i = 0 ; i<graph[s].size() ; i++){
        if(already == false){
        if(hasPath(graph,graph[s][i].n,d,marked))
            return true;
        }
    }

    return false;

}

int main(){
   vector <vector<Edge>> graph = createGraph(7,8);
   int s; cin>>s;
   int d; cin>>d;
   vector <int> marked;
    bool ans = hasPath(graph,s,d,marked);
    cout<<ans;
    
  

}