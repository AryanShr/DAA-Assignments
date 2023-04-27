#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        int V,E;
        vector<vector<int>> adj;
        Graph(int V){
            this->V=V;
        }
        void addEdge(int u,int v,int w){
            adj.push_back({u,v,w});
            adj.push_back({v,u,w});
        }
};

// check acyclic using bfs

bool isCyclic(vector<vector<int>> graph,vector<int> edge){
    vector<vector<int>> mst = graph;
    unordered_map<int,bool> visited;
    for(auto i:mst){
        visited[i[0]]=false;
        visited[i[1]]=false;
    }
    queue<int> q;
    q.push(edge[0]);
    visited[edge[0]]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto i:mst){
            if(i[0]==u && !visited[i[1]]){
                q.push(i[1]);
                visited[i[1]]=true;
            }
            else if(i[1]==u && !visited[i[0]]){
                q.push(i[0]);
                visited[i[0]]=true;
            }                                               
        }
    }
    if(visited[edge[1]]) return true;
    return false;
    
}

void kruskal(Graph& g){
    sort(g.adj.begin(),g.adj.end(),[](vector<int> a,vector<int> b){
        return a[2]<b[2];
    });
    vector<vector<int>> mst;
    // cout<<mst.size()<<" "<<endl;
    for(auto i:g.adj){
        if(mst.empty()) mst.push_back({i[0],i[1],i[2]});
        else if(!isCyclic(mst,i)){
            mst.push_back({i[0],i[1],i[2]});
        }
    }
    for(auto i:mst){
        cout<<i[0]<<"-"<<i[1]<<" "<<i[2]<<endl;
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
    cout<<"Edge weight"<<endl;
    kruskal(graph);
    return 0;
}

