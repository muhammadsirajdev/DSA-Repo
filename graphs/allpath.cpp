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
void dfsmodified(vector<Edge>graph[],bool visisted[],int curr,string s,int tar){//all path from source to target
//curr is the current/starting node, s is the string that stores the path, tar is the target node
    if(curr==tar){ //if the current node is the target node
        cout<<s<<endl;
        return; //return to the previous node and check for other neighbours and find the path
    }
    
    for(int i=0;i<graph[curr].size();i++){//for all the neighbours of the current node
        Edge e=graph[curr].at(i);
        if(visisted[e.dest]==false){
            visisted[curr]=true;
            dfsmodified(graph,visisted,e.dest,s+to_string(e.dest),tar);//recursively call the function//add the current node to the path//
            visisted[curr]=false;
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
    string s=" ";
    // dfs(graph,visited,0,s);
    //bool visited[vertices] = {false};
    // for (int i = 0; i < vertices; i++)
    // {
    //     if(visited[i]==false){
    //         dcdfs(graph,visited,i);
    //     }
    // }
    
    
    
   // getneighbour(graph);
   dfsmodified(graph,visited,0,s,5);

    return 0;
}