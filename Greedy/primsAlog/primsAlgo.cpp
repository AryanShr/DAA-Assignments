#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        int V,E;
        vector<pair<int,int>> *adj;
        Graph(int V){
            this->V=V;
            adj=new vector<pair<int,int>>[V];
        }
        void addEdge(int u,int v,int w){
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
};

void primsAlgo(Graph *graph){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<bool> visited(graph->V,false);
    vector<int> key(graph->V,INT_MAX);
    vector<int> parent(graph->V,-1);
    pq.push({0,0});
    key[0]=0;
    while(!pq.empty()){
        pair<int,int> p=pq.top();
        pq.pop();
        visited[p.second]=true;
        for(auto it=graph->adj[p.second].begin();it!=graph->adj[p.second].end();it++){
            if(!visited[it->first] && it->second<key[it->first]){
                key[it->first]=it->second;
                parent[it->first]=p.second;
                pq.push({key[it->first],it->first});
            }
        }
    }
    for(int i=1;i<graph->V;i++){
        cout<<parent[i]<<"-"<<i<<endl;
    }

}

int main(){
    int V=9;
    Graph *graph=new Graph(V);
    graph->addEdge(0,1,4);
    graph->addEdge(0,7,8);
    graph->addEdge(1,2,8);
    graph->addEdge(1,7,11);
    graph->addEdge(2,3,7);
    graph->addEdge(2,8,2);
    graph->addEdge(2,5,4);
    graph->addEdge(3,4,9);
    graph->addEdge(3,5,14);
    graph->addEdge(4,5,10);
    graph->addEdge(5,6,2);
    graph->addEdge(6,7,1);
    graph->addEdge(6,8,6);
    graph->addEdge(7,8,7);
    primsAlgo(graph);
    return 0;
}