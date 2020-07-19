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
    vi v(n, 0);
    for(int i=0; i<n ; i++)
        cin>>v[i];
    
    bool flag=true;
    for(int i=1; i<n; i++){
        if(v[i]<v[i-1]){
            flag=false;
        }
    }

    if(flag){
        cout<<"0"<<endl;
        return;
    }

    int descStart=v.size()-1;

    for(int i=v.size()-2; i>=0; i--){
        if(v[i]<v[i+1]){
            break;
        }
        descStart=i;
    }

    if(descStart==0){
        cout<<0<<endl;
        return;
    }

    int ascEnd=descStart-1;
    int ascStart=ascEnd;
    for(int i=ascEnd; i>=1; i--){
        if(v[i-1]>v[i])
            break;
        ascStart=i-1;
    }

    cout<<ascStart<<endl;
    return;



}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}