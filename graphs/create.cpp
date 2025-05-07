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
void createGraph(vector<Edge> graph[], int vertices){
    for (int i = 0; i < vertices; i++)
    {
        graph[i] = vector<Edge>();
    }
    graph[0].push_back(Edge(0,2));
    graph[1].push_back(Edge(1,2));
    graph[1].push_back(Edge(1,3));
    graph[2].push_back(Edge(2,0));
    graph[2].push_back(Edge(2,1));
    graph[2].push_back(Edge(2,3));
    graph[3].push_back(Edge(3,1));
    graph[3].push_back(Edge(3,2));
}
void getneighbour(vector<Edge> graph[]){
    for(int i=0;i<graph[2].size();i++){
        Edge e= graph[2].at(i);
        cout<<e.dest<<" | ";
    }
}
    
    
int main(){
    int vertices = 5; 
    vector<Edge> graph[vertices];
    createGraph(graph, vertices);
    getneighbour(graph);

    return 0;
}