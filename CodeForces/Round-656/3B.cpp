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
    int n; 
    cin>>n;
    set<int> ans;

    for(int i=0; i<(2*n); i++){
        int t;
        cin>>t;
        if(ans.find(t)==ans.end()){
            ans.insert(t);
            cout<<t<<" ";
        }
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}