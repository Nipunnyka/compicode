#include<bits/stdc++.h>
#define fi first
#define se second
#define pi pair<int, int>
#define pb push_back

#define mp make_pair
#define ptr (*it)
#define ll long long
#include <chrono> 

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std::chrono; 
using namespace std;

int matrix[30][30];



void solve(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>matrix[i][j];
        }
    }
    int moves=0;
    //func(0,0,n-1,m-1,moves);

    vector<vector<set<pi>>> dp(2);
    dp[0]=vector<set<pi>>((n+m-1)/2);
    dp[1]=vector<set<pi>>((n+m-1)/2);
    
    dp[0][0].insert(mp(0,0));
    dp[1][0].insert(mp(n-1,m-1));
    if(matrix[0][0]!=matrix[n-1][m-1]){
        matrix[n-1][m-1]=matrix[0][0];
        moves++;
    }

    for(int i=1; i<(n+m-1)/2; i++){
        int num1=0,num0=0;
        for(auto &e: dp[0][i-1]){
            if(e.fi+1<n && dp[0][i].find(mp(e.fi+1,e.se))==dp[0][i].end())
            {   dp[0][i].insert(mp(e.fi+1,e.se));
                if(matrix[e.fi+1][e.se]==1)
                    num1++;
                else 
                    num0++;
            }
            if(e.se+1<m && dp[0][i].find(mp(e.fi,e.se+1))==dp[0][i].end())
            {   dp[0][i].insert(mp(e.fi,e.se+1));
                
                if(matrix[e.fi][e.se+1]==1)
                    num1++;
                else 
                    num0++;
            }
            
        }
        bool flag1=false;
        if(num1>num0)
            flag1=true;
        if(flag1){
            for(auto &e: dp[0][i]){
                if(matrix[e.fi][e.se]==0)
                {   matrix[e.fi][e.se]==1; 
                    moves++;
                }
            }
        }
        else{
            for(auto &e: dp[0][i]){
                cout<<e.fi<<", "<<e.se<<endl;
                if(matrix[e.fi][e.se]==1)
                {   matrix[e.fi][e.se]==0; 
                    moves++;
                    cout<<"changed to zero";
                }
            }
        }
        for(auto &e: dp[1][i-1]){
            if(e.fi-1>0 && dp[1][i].find(mp(e.fi-1,e.se))==dp[1][i].end())
            {   dp[1][i].insert(mp(e.fi-1,e.se));
                if(flag1 && matrix[e.fi-1][e.se]==0){
                    moves++;
                    matrix[e.fi-1][e.se]=1;
                }
                else if(!flag1 && matrix[e.fi-1][e.se]==1 ){
                    moves++;
                    matrix[e.fi-1][e.se]==0;
                }
            }
            if(e.se-1>0 && dp[1][i].find(mp(e.fi,e.se-1))==dp[1][i].end())
            {   dp[1][i].insert(mp(e.fi,e.se-1));
                if(flag1 && matrix[e.fi][e.se-1]==0){
                    moves++;
                    matrix[e.fi-1][e.se]=1;
                }
                else if(!flag1 && matrix[e.fi][e.se-1]==1){
                    moves++;
                    matrix[e.fi][e.se-1]==1;
                }
            }
        }
    } 
    cout<<moves<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}