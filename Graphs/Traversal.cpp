#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>

using namespace std;

class graph{
    public:
        unordered_map<int,list<int> >adj;

        void addEdge(int u,int v,bool direction){
            adj[u].push_back(v);
            if(direction ==0){
                adj[v].push_back(u); 
            }
        }
        void printList(){
            for(auto i : adj){
                cout<<i.first<<"-> ";
                for(auto j: i.second){
                    cout<<j<<", ";
                }
                cout<<endl;
            }
        }
};


//<----------------------------------------BFS TRAVERSAL------------------------------------------->
void bfs(vector<int>adj[], unordered_map<int,bool>&visited,int node, vector<int>&ans){
    queue<int>q;
    q.push(node);
    visited[node] = 1;
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for(auto i : adj[front]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
vector<int> bfsOfGraph(int v, vector<int> adj[]) {

    unordered_map<int,bool>visited;
    vector<int>ans;
    for(int i = 0;i<v;i++){
        if(!visited[i]){
            bfs(adj,visited,i,ans);
        }
    }
        
    return ans;
        
}

//<--------------------------------------------DFS TRAVERSAL------------------------------------------->
void dfs(vector<int>adj[],unordered_map<int,bool>&visited, int node,vector<int>&ans){
    ans.push_back(node);
    visited[node] = 1;
    
    for(auto i : adj[node]){
        if(!visited[i]){
            dfs(adj,visited,i,ans);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    unordered_map<int,bool>visited;
    vector<int>ans;
    for(int i = 0;i<V;i++){
        if(visited[i] == 0){
            dfs(adj,visited,i,ans);
        }
    }
    return ans;
}


int main(){
     int n,m;
     cout<<"Enter no of nodes and edges"<<endl;
     cin>>n>>m;
     graph g;
     for(int i =0;i<n;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
     }
     g.printList();

    return 0;
}
