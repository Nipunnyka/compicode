//TO RUN WITH DECLTYPE SUPPORT: g++ -std=c++1z {$filename}.cpp
#include <iostream>
#include<bits/stdc++.h>
#define fi first
#define se second
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define ptr (*it)
#define vi vector<int>
#define vpi vector<pi>
using namespace std;

#include <string_view>

template <typename T>
constexpr std::string_view 
type_name()
{
    std::string_view name, prefix, suffix;
#ifdef __clang__
    name = __PRETTY_FUNCTION__;
    prefix = "std::string_view type_name() [T = ";
    suffix = "]";
#elif defined(__GNUC__)
    name = __PRETTY_FUNCTION__;
    prefix = "constexpr std::string_view type_name() [with T = ";
    suffix = "; std::string_view = std::basic_string_view<char>]";
#elif defined(_MSC_VER)
    name = __FUNCSIG__;
    prefix = "class std::basic_string_view<char,struct std::char_traits<char> > __cdecl type_name<";
    suffix = ">(void)";
#endif
    name.remove_prefix(prefix.size());
    name.remove_suffix(suffix.size());
    return name;
}

class Graph{
    public:
    int n;
    int m;
    vector<vector<pi>> adj;
    
    Graph(int n, int m){
        this->n=n;
        this->m=m;
        vector<vector<pi>> adj;
    }

    void inputGraph(){
        cout<<"input edges"<<endl;
        vpi p(100, mp(0,0));
        adj.resize(n);
        while(m--){
            int src,dest,wt;
            cin>>src>>dest>>wt;
            adj[src].pb(mp(dest,wt));
            cout<<"added: "<<src<<" "<<dest<<" "<<wt<<endl;
        }
        cout<<"check";
    }

    void printGraph(){
        for(int i=0; i<n; i++){
            cout<<i<<" --> ";
            for(auto it=adj[i].begin(); it!=adj[i].end(); it++){
                cout<<ptr.fi<<" with a wt of "<<ptr.se<<", ";
            }
            cout<<endl;
        }
    }

    void DFS_ts(int start, vector<bool>& vis, vector<int>& ans){
        vis[start]=true;
        for(auto it=adj[start].begin(); it!=adj[start].end(); it++){
            if(!vis[ptr.fi]){
                vis[ptr.fi]=true;
                DFS_ts(ptr.fi, vis, ans);
            }
        }
        ans.pb(start);
    }

    vector<int> topSort(){
        vector<bool> vis(n, false);
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                DFS_ts(i, vis, ans);
            }
        }
        //reverse ans and eturn
        //ans.reverse();
        return ans;
    }

    void edge_relax_ts(int start, vector<bool>& vis, vector<int>&dist){
        vis[start]=true;
        for(auto it=adj[start].begin(); it!=adj[start].end(); it++){
            int newdist=dist[start]+ptr.se;
            if(newdist<dist[ptr.fi]){
                dist[ptr.fi]=newdist;
            }
        }
    }

    int topSort_shortestPath(int start, int end){
        vector<int> topsort=topSort();
        vector<int> dist(n, INT_MAX);
        //INCOMPLETE
        return dist[end];
    }

    void DFS(int src, vector<bool>* visited){
        (*visited)[src]=true;
        cout<<src<<" ";
        for(auto it=adj[src].begin(); it!=adj[src].end(); it++){
            if(!(*visited)[ptr.fi]){
                (*visited)[ptr.fi]=true;
                DFS(ptr.fi, visited);
            }
        }
    }

    void BFS(int src){
        vector<bool> vis(n, false);
        queue<int> q;
        vis[src]=true;
        q.push(src);
        while(!q.empty()){
            int front=q.front();
            cout<<front<<" ";
            q.pop();
            for(auto &e: adj[front]){
                if(!vis[e.fi]){
                    vis[e.fi]=true;
                    q.push(e.fi);
                }
            }
        }
        cout<<endl;
    }

    //return num of connected components
    int connectedComp(){
        vector<bool> visitied(n, false);
        int k=0;
        for(int i=0; i<n; i++){
            if(!visitied[i]){
                k++;
                DFS(i, &visitied);
            }
        }
        return k;
    }
    //returns the min move to reach dest
    int bfsPathSearch(int src, int end){
        cout<<"here";
        if(src==end)
            return 0;
        int moves=0;
        int nodesLeft=1;
        int nodesNext=0;
        vector<bool> vis(n, false);
        queue<int> q;
        vis[src]=true;
        q.push(src);
        bool found=false;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            if(front==end){
                found= true;
                break;
            }
            //explore neighburs
            for(auto &e: adj[front]){
                if(!vis[e.fi]){
                    vis[e.fi]=true;
                    q.push(e.fi);
                    nodesNext++;
                }
            }
            nodesLeft--;
            if(nodesLeft==0){
                nodesLeft=nodesNext;
                nodesNext=0;
                moves++;
            }
        }
        if(found==true){
            return moves;
        }
        else 
            return -1;
    }

    


};

int main(){
    int n; cin>>n;
    Graph g(n, n-1);
    g.inputGraph();
    return 0;
}
