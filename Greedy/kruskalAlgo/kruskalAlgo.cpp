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

int find(int parent[],int i){
    if(parent[i]==-1)
        return i;
    return find(parent,parent[i]);
}

void unionSet(int parent[],int x,int y){
    int xset=find(parent,x);
    int yset=find(parent,y);
    parent[xset]=yset;
}

void kruskal(Graph g){
    sort(g.adj.begin(),g.adj.end(),[](vector<int> a,vector<int> b){
        return a[2]<b[2];
    });
    int parent[g.V];
    memset(parent,-1,sizeof(parent));
    vector<vector<int>> mst;
    for(auto i:g.adj){
        int x=find(parent,i[0]);
        int y=find(parent,i[1]);
        if(x!=y){
            mst.push_back({i[0],i[1],i[2]});
            unionSet(parent,x,y);
        }
    }
    int sum = 0;
    for(auto i:mst){
        cout<<i[0]<<"-"<<i[1]<<"      "<<i[2]<<endl;
        sum += i[2];
    }
    cout<<"Total weight of MST is "<<sum<<endl;

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