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
void Bfs(vector<Edge> graph[],int vertex,int src){
    queue<int> q;
    q.push(src);
    bool visited[vertex] = {false};
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        if(visited[u]==false){
            cout<<u<<" ";
            visited[u]=true;
            for (int i = 0; i < graph[u].size(); i++)
            {
                Edge e=graph[u].at(i);
                q.push(e.dest);
            }
        }
    }
    cout<<endl;
}
void dcBfs(vector<Edge> graph[],int src,bool visited[]){// multiple disconnected graphs
    queue<int> q;
    q.push(src);
    
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        if(visited[u]==false){
            cout<<u<<" ";
            visited[u]=true;
            for (int i = 0; i < graph[u].size(); i++)
            {
                Edge e=graph[u].at(i);
                q.push(e.dest);
            }
        }
    }
    cout<<endl;
}
// void getneighbour(vector<Edge> graph[]){
//     for(int i=0;i<graph[2].size();i++){
//         Edge e= graph[2].at(i);
//         cout<<e.dest<<" | ";
//     }
// }
    
    
int main(){
    int vertices = 4; 
    vector<Edge> graph[vertices];
    createGraph(graph, vertices);
    Bfs(graph,vertices,0);
    bool visited[vertices] = {false};
    for (int i = 0; i < vertices; i++)
    {
        if(visited[i]==false){
            dcBfs(graph,i,visited);
        }
    }
    // getneighbour(graph);

    return 0;
}