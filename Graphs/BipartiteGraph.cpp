#include<iostream>
#include<vector>

using namespace std;

// A graph is a bipartite graph if and only if it does not contain an odd cycle
// We check for an odd cycle in the graph by checking that whether we can colour the graph with exactly 2 colours(0 and 1) or not.
// Colouring must be in such a way that no two adjacent nodes have the same colour.

bool dfs(int node,int col, vector<int>&visited,vector<vector<int>>& graph){
    visited[node] = col;

    for(auto i : graph[node]){
        if(visited[i] == -1){
            if(!dfs(i, 1 - col, visited, graph))  return false;
        }else if(visited[i] == col){
            return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int>visited(n,-1);
    for(int i = 0;i<n; i++){
        if(visited[i] == -1){
            bool odd_cycle = !dfs(i,0, visited, graph);
            if(odd_cycle){
                return false;
            }
        }
        
    }
    return true;
    
}
