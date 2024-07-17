#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>

using namespace std;

//<----------------------------------------CYCLE DETECTION USING DFS-------------------------------------------->
bool dfs(vector<int>adj[],vector<bool>&visited,int node,int parent){
    visited[node] = 1;
    
    for(int i : adj[node]){
        if(!visited[i]){
            if(dfs(adj,visited,i,node)) return true;
        }else{
            if(i != parent){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool>visited(V);
    for(int i = 0;i<V;i++){
        if(!visited[i]){
            if(dfs(adj,visited,i,-1)) return true;
            
        }
    }
    return false;
}

//<------------------------------------CYCLE DETECTION USING BFS----------------------------------------------------->
bool bfs(vector<int>adj[], vector<bool>&visited,int node){
    vector<int>parent(visited.size());
    queue<int>q;
    
    visited[node] = 1;
    parent[node] = -1;
    q.push(node);
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(int i : adj[front]){
            if(visited[i] && i != parent[front]){
                return true;
            }else if(!visited[i]){
                visited[i] = 1;
                parent[i] = front;
                q.push(i);
            }
        }
    }
    
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool>visited(V,0);
    for(int i = 0;i<V;i++){
        if(!visited[i]){
            if(bfs(adj,visited,i)) return true;
        }
    }
    return false;
}

//<-----------------------------------------CYCLE DETECTION IN DIRECTED GRAPH-------------------------------------------->
bool dfs(vector<int>adj[], vector<bool>&visited, vector<bool>&dfsvisited,int node){
    visited[node] = 1;
    dfsvisited[node] = 1;
    
    for(int i : adj[node]){
        if(!visited[i]){
            if(dfs(adj,visited,dfsvisited,i)) return true;
        }else{
            if(dfsvisited[i]) return true;
        }
    }
    
    dfsvisited[node] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<bool>visited(V);
    vector<bool>dfsvisited(V);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(dfs(adj,visited,dfsvisited,i)) return true;
        }
    }
    return false;
}

//<------------------------------------------------TOPO SORT------------------------------------------------------------>
void dfs(vector<int>adj[],vector<bool>&visited,int node, stack<int>&s){
    visited[node] = 1;
    
    for(int i : adj[node]){
        if(!visited[i]){
            dfs(adj,visited,i,s);
        }
    }
    s.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<bool>visited(V);
    stack<int>s;
    
    for(int i = 0;i<V;i++){
        if(!visited[i]){
            dfs(adj,visited,i,s);
        }
    }
    
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;
}

//<------------------------------------TOPO SORT(KAHN'S ALGORITHM)-------------------------------------------->
vector<int> topoSort(int V, vector<int> adj[]) {
    //step1: calculate indegree
    vector<int>indegree(V);
    vector<int>ans;
    
    for(int i = 0;i<V;i++){
        for(int j : adj[i]){
            indegree[j]++;
        }
    }
    //step2: if indegree is 0 then pudh in queue
    queue<int>q;
    for(int i = 0;i<V;i++){
        if(indegree[i] == 0) q.push(i);
    }
    
    //step3: Do BFS
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        
        for(auto i : adj[front]){
            indegree[i]--;
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    }
    return ans;
}

//<-------------------------------------------CYCLE DETECTION USING TOPO SORT------------------------------------>

bool isCyclic(int n, vector<int> adj[]) {
    vector<int>indegree(n, 0);

    for(int i = 0;i<n;i++){
        for (auto it : adj[i]) {
        indegree[it]++;
        }
    }
    queue<int>q;
    vector<int>topo_sort;
    for(int i = 0;i<n;i++){
        if(indegree[i] == 0)  q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo_sort.push_back(node);
        for(auto i: adj[node]){
        indegree[i]--;
        if(indegree[i] == 0) q.push(i);
        }
    }
    return (topo_sort.size() == n? 0:1);
}
