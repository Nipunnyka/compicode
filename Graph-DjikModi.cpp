/*
solution to problem: https://codeforces.com/contest/715/problem/B

*/

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi pair<int, int>
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
    int n; //vertices;
    int m; //edges
    list<pair<int ,int>> *adj;
    
    
    Graph(int n, int m){
        this->n=n;
        this->m=m;
        adj=new list<pi>(n);
    }
    
    Graph(int n){
        this->n=n;
        m=n-1;
        adj=new list<pi>;
    }
    
    void inputGraph(){
        cout<<"input edges"<<endl;
        while(m--){
            int src,dest,wt;
            scanf("%d", &src);
            scanf("%d", &dest);
            scanf("%d", &wt);
            adj[src].pb(mp(dest,wt));
        }
    }
    
    int inputGraphModified(){
        int count=0;
        cout<<"input edges"<<endl;
        while(m--){
            int src,dest,wt;
            scanf("%d", &src);
            scanf("%d", &dest);
            scanf("%d", &wt);
            if(wt==0){
                count++;
            }
            adj[src].pb(mp(dest,wt));
        }
        return count;
    }
    
    //virtual ~Graph();
    
};

//returns the prev array and cost
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
            if(index==t){
                return mp(dist[t], prev);
            }
        }
    }
}

void solve(Graph G, int l, int s, int t, int countZeros){
    vector<int> path;
    int cost=0;
    pair<int, vector<int>> p=djikstraModi(G,s,t);
    if(p.fi==l){
        cout<<"yes";
        return;
    }
    
    //find num of zeros in path;
    vector<int> prev=p.se;
    int index=t;
    path.pb(index);
    int count=0;
    while(prev[index]!=index){
        path.pb(prev[index]);
        for(auto it=G.adj[prev[index]].begin(); it!=G.adj[prev[index]].end(); it++){
            if((*it).se==0 && (*it).fi==index)
                count++;
        }
    }
    
    if(p.fi<l && count==0){
        cout<<"no"<<endl;
        return;
    }
    
    else if(p.fi>l && count>0){
        cout<<"no"<<endl;
        return;
    }
    
    //PATH IS REVERSED
    //when will ans be no
        //1. no zeros and path <l
        
        //2. zeros and path>L
     
}

int main()
{
    int n, m;
    //Graph G;
    cout<<"enter num of vertice and edges"<<endl;
    cin>>n>>m;
    Graph G(n,m);
    cout<<"enter l s t"<<endl;
    int l, s, t;
    cin>>l>>s>>t;
    int countZeros=G.inputGraphModified();
    solve(G, l, s, t, countZeros);
    return 0;
}
