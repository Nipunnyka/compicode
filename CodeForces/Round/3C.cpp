#include <iostream>
#include<bits/stdc++.h>
#define fi first
#define se second
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define ptr (*it)
#define ll long long
#include <chrono> 
#define _USE_MATH_DEFINES
#define vl vector<ll>
#define vi vector<int>
#include <cmath>
#include <iostream>
#define pli pair<ll, int>
#define pl pair<ll, ll>

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
    int n, k;
    FAST;
    cin>>n>>k;
    string s;
    cin>>s;
    vi v(n);
    int max_val=(2*k)+1;
    bool max_reached=false;
    int i=0;
    int ans=0;
    for(auto &e: s){
        if(e=='1'){
            v[i]=0;
            max_reached=false;
        }
        else if(e=='0'){
            if(max_reached){
                v[i]=k+1;
                max_reached=false;
            }
            else{
                v[i]=i>0?1+v[i-1]:1;
            }
            if(v[i]==max_val || (v[i]>k&&i==n-1) || (v[i]==k+1&&(i-k)==0))
            {
                 max_reached=true;
                 ans++;
            }
        }
        i++;
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
}