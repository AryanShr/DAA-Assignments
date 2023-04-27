#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        int V;
        vector<vector<int>> adj;
        Graph(int V){
            this->V=V;
        }
        void addEdge(int u,int v,int w){
            adj.push_back({u,v,w});
            adj.push_back({v,u,w});
        }
};


void dijkstra(Graph g,int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(g.V,INT_MAX);
    pq.push({src,0});
    dist[src]=0;
    while(!pq.empty()){
        int u=pq.top().first;
        pq.pop();
        for(int i = 0;i<g.adj.size();i++){
            
        }
    }
    for(int i=0;i<g.V;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
}

int main(){
    int V=9;
    Graph graph(V);
    graph.addEdge(0,1,4);
    graph.addEdge(0,7,8);
    graph.addEdge(1,2,8);
    graph.addEdge(1,7,11);
    graph.addEdge(2,3,7);
    graph.addEdge(2,8,2);
    graph.addEdge(2,5,4);
    graph.addEdge(3,4,9);
    graph.addEdge(3,5,14);
    graph.addEdge(4,5,10);
    graph.addEdge(5,6,2);
    graph.addEdge(6,7,1);
    graph.addEdge(6,8,6);
    graph.addEdge(7,8,7);

    dijkstra(graph,0);
    return 0;
}