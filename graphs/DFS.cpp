#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int src;
    int dest;
    Edge(int s,int d){
        this->src=s;
        this->dest=d;
    }
};
void createGraph(vector<Edge> graph[], int vertices){// ak array bnanyngy jis
// ka har element vector ho ga,
// vector may edge ka object hoga,isi lia hmne array ka type vector<Edge> bnaya h 
//taki hr ak element may 
//vector ho jis may edge ka object ho, graph[0] may 0 sy agay dsry vertex pa
// jany wali edge h, 
    for (int i = 0; i < vertices; i++)
    {
        graph[i] = vector<Edge>(); // har element may vector<Edge> ka object bnaya wrna error a jata qki initially koi edge nhi hoti
    }
    graph[0].push_back(Edge(0,1));
    graph[0].push_back(Edge(0,2));
    graph[1].push_back(Edge(1,3));
    graph[2].push_back(Edge(2,4));
    graph[3].push_back(Edge(3,4));
    graph[3].push_back(Edge(3,5));
    graph[4].push_back(Edge(4,3));
    graph[4].push_back(Edge(4,5));
    graph[5].push_back(Edge(5,3));
    graph[5].push_back(Edge(5,4));
    graph[5].push_back(Edge(5,6));
    graph[6].push_back(Edge(6,5));
};
// uses reccursion, uses visited arrya to keep track of visited nodes,
// uses stack to keep track of nodes to be visited
//
void dfs(vector<Edge>graph[],bool visisted[],int curr){
    cout<<curr<<" ";
    visisted[curr]=true;
    for(int i=0;i<graph[curr].size();i++){
        Edge e=graph[curr].at(i);
        if(visisted[e.dest]==false){
            dfs(graph,visisted,e.dest);
        }
    }
    cout<<endl;
}
void dcdfs(vector<Edge>graph[],bool visisted[],int curr){//disconnected graph
    cout<<curr<<" ";
    visisted[curr]=true;
    for(int i=0;i<graph[curr].size();i++){
        Edge e=graph[curr].at(i);
        if(visisted[e.dest]==false){
            dfs(graph,visisted,e.dest);
        }
    }
}


void getneighbour(vector<Edge> graph[]){
    for(int i=0;i<graph[2].size();i++){
        Edge e= graph[2].at(i);
        cout<<e.dest<<" | ";
    }
}
    
    
int main(){
    int vertices = 7; 
    vector<Edge> graph[vertices];
    createGraph(graph, vertices);
    bool visited[vertices]={false};
    dfs(graph,visited,0);
    //bool visited[vertices] = {false};
    // for (int i = 0; i < vertices; i++)
    // {
    //     if(visited[i]==false){
    //         dcdfs(graph,visited,i);
    //     }
    // }
    
    
    
   // getneighbour(graph);

    return 0;
}