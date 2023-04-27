#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int src,dest,weight;
};

class Graph{
    public:
        int V,E;
        Edge *edge;
        Graph(int V,int E){
            this->V=V;
            this->E=E;
            edge=new Edge[E];
        }
};

int find(int parent[],int i){
    if(parent[i]==-1)
        return i;
    return find(parent,parent[i]);
}

void Union(int parent[],int x,int y){
    int xset=find(parent,x);
    int yset=find(parent,y);
    parent[xset]=yset;
}

int isCycle(Graph *graph){
    int *parent=new int[graph->V];
    memset(parent,-1,sizeof(int)*graph->V);
    for(int i=0;i<graph->E;i++){
        int x=find(parent,graph->edge[i].src);
        int y=find(parent,graph->edge[i].dest);
        if(x==y)
            return 1;
        Union(parent,x,y);
    }
    return 0;
}

int main(){
    int V=3,E=3;
    Graph *graph=new Graph(V,E);
    graph->edge[0].src=0;
    graph->edge[0].dest=1;
    graph->edge[0].weight=1;
    graph->edge[1].src=1;
    graph->edge[1].dest=2;
    graph->edge[1].weight=1;
    graph->edge[2].src=0;
    graph->edge[2].dest=2;
    graph->edge[2].weight=1;
    if(isCycle(graph))
        cout<<"Graph contains cycle";
    else
        cout<<"Graph doesn't contain cycle";
    return 0;
}