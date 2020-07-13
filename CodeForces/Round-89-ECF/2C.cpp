#include<bits/stdc++.h>
#define fi first
#define se second
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
#define mp make_pair
#define ptr (*it)
#define ll long long
#include <chrono> 

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std::chrono; 
using namespace std;

void solve(){
    FAST;
    int n,m; 
    cin>>n>>m;
    vector<vi> mat(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
        }
    }
    //cout<<"input matrix";
    vector<vi> dp(n+m-1, vi(2) );

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dp[i+j][mat[i][j]]++;
        }
    }
    ll ans=0;

    for(int i=0; i<=(n+m-2)/2; i++){
        int j=n+m-2-i;
        if(i<j){
         ans+=min(dp[i][0]+dp[j][0], dp[i][1]+dp[j][1]);
        }
    }
    cout<<ans<<endl;
    return;
}

int main(){
    int t;
    FAST;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}