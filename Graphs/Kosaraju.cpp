//TO RUN WITH DECLTYPE SUPPORT: g++ -std=c++1z {$filename}.cpp
#include <iostream>
#include<bits/stdc++.h>
#define fi first
#define se second
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define ptr (*it)

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
        adj.resize(n);
        while(m--){
            int src,dest,wt;
            cin>>src>>dest;
            wt=1;
            adj[src].pb(mp(dest,wt));
        }
        cout<<"input end"<<endl;
    }
     
    Graph reverseGraph(){
        Graph G(n,m);
        G.adj.resize(n);
        for(int i=0; i<n; i++){
            for(auto it=adj[i].begin(); it!=adj[i].end(); it++){
                G.adj[ptr.fi].pb(mp(i, ptr.se));
            }
        }
        return G;
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

    //this updates stack if src has been explored completetly
    void DFSUtil(int src, vector<bool>* visited, stack<int>* st){
        (*visited)[src]=true;
        for(auto it=adj[src].begin(); it!=adj[src].end(); it++){
            if(!(*visited)[ptr.fi]){
                (*visited)[ptr.fi]=true;
                DFSUtil(ptr.fi, visited, st);
            }
        }
        (*st).push(src);
    }

    //this is the dfs for a reversed graph ith returns all the vertices of strongly cnnected comp
    void DFS2(Graph G, set<int> * ans, vector<bool>* visited, int index){
        
        (*visited)[index]=true;
        (*ans).insert(index);
        for(auto it=G.adj[index].begin(); it!=G.adj[index].end(); it++){
            if(!(*visited)[ptr.fi]){
                (*visited)[ptr.fi]=true;
                DFS2(G, ans, visited, ptr.fi);
            }
        }

    }

    //want to return indices of head of all SC
    vector<set<int>> findSC(){
        vector<bool> visited(n, false);
        stack<int> st;
        for(int i=0; i<n; i++){
            if(!visited[i])
                DFSUtil(i, &visited, &st);
        }
        

        Graph newG=reverseGraph();
        for(int i=0; i<n; i++)
            visited[i]=false;

        set<int> comp;
        vector<set<int>> ans;
        while(!st.empty()){
            comp.clear();
            int index=st.top();
            st.pop();
            if(visited[index]){
                continue;
            }
            DFS2(newG, &comp, &visited, index);
            ans.pb(comp);

        }
        return ans;
    }
};

int main(){

    Graph g(3,0);
    g.inputGraph();
    vector<set<int>> ans;
    ans=g.findSC();
    for(auto &it: ans){
        //cout<<"check "<<it.size();
        for(auto &e: it){
            cout<<e<<" ";
        }
        cout<<endl;
    }

    return 0;
}