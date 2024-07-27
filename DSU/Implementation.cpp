#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
//<----------------------------------------------PRIM'S ALGORITHM TO FIND MST----------------------------------------------->
// Start from a node, check the adj nodes and select the minimum weight edge
int spanningTree(int V, vector<vector<int>> adj[])
{
    // pq of weight, node and parent
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
                    greater<pair<int,pair<int,int>> > >pq;
                    
    vector<int>visited(V);
    pq.push({0,{0,-1}});
    
    int sum = 0;
    while(!pq.empty()){
        auto front = pq.top();
        int wt = front.first;
        int node = front.second.first;
        int parent = front.second.second;
        
        pq.pop();
        
        if(visited[node] == 1) continue;
        
        visited[node] = 1;
        sum += wt;
        
        for(auto i : adj[node]){
            int adjnode = i[0];
            int adjwt = i[1];
            if(!visited[adjnode]){
                pq.push({adjwt, {adjnode, node}});
            }
            
        }
    }
    return sum;
}
//<----------------------------------------------KRUSKAL'S ALGORITHM TO FIND MST------------------------------------------->
// The idea is to select the minimum wt edge such that it does not form a cycle
class DisjointSet{
    public:
    vector<int>rank,parent,size;

    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 0;i<=n;i++){
            parent[i] = i;
        }
    }
   
    int findParent(int u){
        if(u == parent[u]){
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }
    void union_by_rank(int u,int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

  
};

//Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<pair<int,pair<int,int>>>edges;
    for(int i = 0;i<V;i++){
        for(auto j : adj[i]){
            int adjnode = j[0];
            int wt = j[1];
            int node = i;
            
            edges.push_back({wt,{node,adjnode}});
        }
    }
    
    sort(edges.begin(),edges.end()); // sorted as per the edge weights
    
    int mst_sum = 0;
    DisjointSet ds(V);
    
    for(auto it: edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(ds.findParent(u) != ds.findParent(v)){
            // u and v were not in the same component
            mst_sum += wt;
            ds.union_by_rank(u,v);
        }
    }
    return mst_sum;
}
