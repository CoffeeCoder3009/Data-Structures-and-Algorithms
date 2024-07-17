#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<set>

using namespace std;

//<-----------------------------------SHORTEST PATH IN UNDIRECTED GRAPH------------------------------------------------->
 vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
    unordered_map<int,vector<int>>adj;
    for(auto i : edges){
            int u = i[0];
            int v = i[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
    }
    
    vector<int>dist(n,INT_MAX);
    //queue of node and their distance from src node
    queue<pair<int,int>>q;
    q.push({src,0});
    
    while(!q.empty()){
        int node = q.front().first;
        int d = q.front().second;
        q.pop();
        
        for(int i : adj[node]){
            if(dist[i] > d+1){
                q.push({i,d+1});
                dist[i] = d+1;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dist[i] == INT_MAX){
            dist[i] = -1;
        }
    }
    return dist;
}

//<---------------------------------------------SHORTEST PATH IN A WEIGHTED DAG---------------------------------------------->
void dfs(unordered_map<int,vector<pair<int,int>>>&adj,vector<bool>&visited,int node,stack<int>&s){
    visited[node] = 1;
    
    for(auto i : adj[node]){
        if(!visited[i.first]){
            dfs(adj,visited,i.first,s);
        }
    }
    
    s.push(node);
}

vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    unordered_map<int,vector<pair<int,int>>>adj;
    
    for(int i = 0;i<M;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        
        adj[u].push_back({v,wt});
        
    }
    
    vector<bool>visited(N,0);
    stack<int>s;
    for(int i = 0;i<N;i++){
        if(!visited[i]){
            dfs(adj,visited,i,s);
        }
    }
    
    vector<int>dist(N,1e9);
    dist[0] = 0;
    
    while(!s.empty()){
        int front = s.top();
        s.pop();
        
        for(auto i : adj[front]){
            if(dist[i.first] > dist[front] + i.second){
                dist[i.first] = dist[front] + i.second;
            }
        }
    }
    for(int i = 0;i<N;i++){
        if(dist[i] == 1e9){
            dist[i] = -1;
        }
    }
    return dist;
}

//<----------------------------------------DIJGSTRA'S ALGORITHM (PRIORITY QUEUE)-------------------------------------------->
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distTo(V, INT_MAX);
    distTo[S] = 0;
    pq.push({0, S});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        
        for (auto it : adj[node])
        {
            int v = it[0];
            int w = it[1];
            if (dis + w < distTo[v])
            {
                distTo[v] = dis + w;
                pq.push({dis + w, v});
            }
        }
    }
    return distTo;
}
//<----------------------------------------DIJGSTRA'S ALGORITHM (USING SET)-------------------------------------------->
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
    set<pair<int,int>>st;
    vector<int>dist(V, INT_MAX);
    dist[S]=0;
    st.insert(make_pair(0,S));
    
    while(!st.empty()){
        auto top= *(st.begin());
        int distNode=top.first;
        int topNode= top.second;
        
        st.erase(top);
        
        //traversing top neighbours
        
        for(auto neighbour: adj[topNode]){
            if(distNode+neighbour[1] < dist[neighbour[0]]){
                auto record=  st.find(make_pair(dist[neighbour[0]], neighbour[0]));
                
                if(record!=st.end()){
                    st.erase(record);
                }
                
                //distance update
                dist[neighbour[0]]=distNode+neighbour[1];
                
                //record push into set
                st.insert(make_pair(dist[neighbour[0]],neighbour[0]));
            }
        }
    }
    return dist;
}

//<--------------------------------------------BELLMAN FORD ALGORITH------------------------------------------------------->
/* 
1) Applicable only for directed graphs
2)Helps in the detection of negative cycles
*/
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    // relax all the edges n-1 times
    // after n-1 iterations dist array gets updated with the minimum distance
    vector<int>dist(V,1e8);
    dist[S] = 0;
    
    for(int i = 0;i<V-1;i++){
        for(auto j : edges){
            int u = j[0];
            int v = j[1];
            int wt = j[2];
            
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    //if on nth relaxation, dist array gets updated, then graph contains a negative cycle
    for(auto i : edges){
        int u = i[0];
        int v = i[1];
        int wt = i[2];
        
        if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
            return {-1}; // returns -1 if -ve cycle is present 
        }
    }
    return dist;
}

//<--------------------------------------------FLOYD WARSHAL ALGORITHM------------------------------------------------------> 
/*
1) Multisource shortest path algorithm, tells shortest distance from all the nodes to all other nodes
2) Helps to detect negative cycle
3) Valid for directed cycle
*/
vector<vector<int>> shortest_distance(vector<vector<int>>&matrix){
    //matrix is n*n which holds a value -1 if there does not exist an edge between i and j
    int n = matrix.size();
    vector<vector<int>>dist = matrix;
    //dist[i][j] = distance of node j from i
    
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j] == -1) dist[i][j] = 1e9;
            if(i == j) dist[i][j] = 0;
        }
    }
    //go via all the vertices to calculate shortest distance to reach j from i
    for(int via = 0;via <n;via++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                dist[i][j] = min(dist[i][j],dist[i][via] + dist[via][j]);
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(dist[i][j] == 1e9) dist[i][j] = -1;
        }
    }
    return dist;
}
