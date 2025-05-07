#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int src;
    int dest;
    int weight;
    Edge(int s,int d,int w){
        this->src=s;
        this->dest=d;
        this->weight=w;
    }
};
void createGraph(vector<Edge> graph[], int vertices){
    for (int i = 0; i < vertices; i++)
    {
        graph[i] = vector<Edge>();
    }
    graph[0].push_back(Edge(0,2,2));
    graph[1].push_back(Edge(1,2,10));
    graph[1].push_back(Edge(1,3,0));
    graph[2].push_back(Edge(2,0,2));
    graph[2].push_back(Edge(2,1,10));
    graph[2].push_back(Edge(2,3,-1));
    graph[3].push_back(Edge(3,1,0));
    graph[3].push_back(Edge(3,2,-1));
}
void getneighbourandweight(vector<Edge> graph[]){
    for(int i=0;i<graph[2].size();i++){
        Edge e= graph[2].at(i);
        cout<< "2 --- " <<e.dest<<" The weight is: "<<e.weight<<" | ";
    }
}
    
    
int main(){
    int vertices = 5; 
    vector<Edge> graph[vertices];
    createGraph(graph, vertices);
    getneighbourandweight(graph);

    return 0;
}