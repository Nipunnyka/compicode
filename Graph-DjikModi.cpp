/*
solution to problem: https://codeforces.com/contest/715/problem/B

*/

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
#define fi first
#define se second
#define pi pair<int, int>
#define pb push_back
#define mp make_pair

using namespace std;

struct myComp { 
    constexpr bool operator()( 
        pair<int, int> const& a, 
        pair<int, int> const& b) 
        const noexcept 
    { 
        return a.second > b.second; 
    } 
};

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
            cin>>src>>dest>>wt;
            //cout<<"going to enter now";
            adj[src].pb(mp(dest,wt));
            adj[dest].pb(mp(src,wt));
            cout<<"m: "<<m<<endl;
        }
        cout<<"input end"<<endl;
    }
    
    int inputGraphModified(){
        int count=0;
        adj.resize(n);
        //cout<<"input edges: "<<m<<endl;
        while(m--){
            int src,dest,wt;
                        cin>>src>>dest>>wt;

            if(wt==0){
                count++;
            }
            adj[src].pb(mp(dest,wt));
            adj[dest].pb(mp(src,wt));
            //cout<<"m: "<<m<<endl;
        }
        //cout<<"ending now"<<endl;
        return count;
    }
    
    ~Graph(){
        cout<<"";
    }
    
};

pair<int, vector<int>> djikstraModi(Graph g, int s, int t){
    priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq;
    vector<int> dist(g.n, INT_MAX);
    vector<bool> visited(g.n, false);
    vector<int> prev(g.n, INT_MAX);
    dist[s]=0;
    prev.pb(s);
    pq.push(mp(s, dist[s]));
    while(!pq.empty()){
        pi p=pq.top();
        pq.pop();
        int index=p.fi;
        int minVal=p.se;
        visited[index]=true;

        if(index==t){
            return mp(dist[t], prev);
        }

        if(dist[index]>=minVal){
            //explore neighbours 
            for(auto it=g.adj[index].begin(); it!=g.adj[index].end(); it++){
                if(!visited[(*it).fi]){
                    int newDist=minVal+(*it).se;
                    if(newDist<dist[(*it).fi]){
                        dist[(*it).fi]=newDist;
                        pq.push(mp((*it).fi,newDist));
                        prev[(*it).fi]=index;
                    }
                }
            }
            
        }
    }
}

void solve(Graph G, int l, int s, int t, int countZeroes){
    vector<int> path;
    int cost=0;
    pair<int, vector<int>> p=djikstraModi(G,s,t);
    
    
    //find num of zeros in path;
    vector<int> prev=p.se;
    //for(auto it=prev.begin(); it!=prev.end(); it++){
    //    cout<<*it<<" ";
    //}
    //cout<<endl;
    int index=t;
    path.pb(index);
    int count=0;
    vector<pi> zeroWtPos;
    while(prev[index]!=INT_MAX){
        path.pb(prev[index]);
        for(auto it=G.adj[index].begin(); it!=G.adj[index].end(); it++){
            if((*it).se==0 && (*it).fi==prev[index])
            {   count++;
                zeroWtPos.pb(mp(index, prev[index]));
            }
        }
        index=prev[index];
    }
    //cout<<"count of zeros in path is"<<count<<endl;
 
    if(p.fi==l && count>0){
        cout<<"NO";
        return;
    }

    if(p.fi<l && (count==0 || (l-p.fi)<count)){
        cout<<"NO";
        return;
    }
    
    else if(p.fi>l){
        cout<<"NO";
        return;
    }
    
    else{
        cout<<"YES"<<endl;
        //unordered_map<pi, bool> vis(G.n, false);
        //pi temp=zeroWtPos[0];
        //G.adj[temp.fi]=mp(temp.se, l-p.fi-count+1);
        //G.adj[temp.se]=mp(temp.fi, l-p.fi-count+1);
        ////print all edges
        //for(int i=0; i<G.n; i++){
        //    //print all neighbours
        //    for(auto it=G.adj[i].begin(); it!=G.adj[i].end(); it++){
        //        if(!(vis[mp(i, (*it).fi)] || vis[mp((*it).fi, i)])){
        //            vis[mp(i, *it.fi)]=true;
        //            (*it).se=(*it).se==0? 1:*it.se;
        //            cout<<i<<" "<(*it).fi<<" "<<(*it).se<<endl;
        //        }
        //    }
        //}
        return;
    }

    //PATH IS REVERSED
    //when will ans be no
        //1. no zeros and path <l
        
        //2. path>L
     
}

int main()
{
    int n, m, l, s, t;
    //cout<<"enter n m l s t"<<endl;
    cin>>n>>m>>l>>s>>t;
    Graph g(n,m);
    int countZeroes=g.inputGraphModified();
    solve(g, l, s, t, countZeroes);

    return 0;
}
