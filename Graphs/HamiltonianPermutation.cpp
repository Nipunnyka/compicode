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
#define vvi vector<vector<int>>
using namespace std;

int main(){
    int n, m, i;
    cin>>n>>m;
    vi v(11, -1);
    vector<vi> adj(11, v);
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        adj[x][y]=adj[y][x]=1;
    }
   

    vi nums;
    for(i=1; i<=n; i++)
        nums.pb(i);
    int cnt=0;
    do{
        bool flag=true;
        for(int i=0; i<n-1; i++){
            if(adj[nums[i]][nums[i+1]]==-1){
                flag=false;
                break;
            }
        }
        if(flag)
            cnt++;
    }while(next_permutation(nums.begin(), nums.end()));
    cout<<cnt<<endl;

    return 0;
}