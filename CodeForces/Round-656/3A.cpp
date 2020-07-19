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
    int x,y,z;
    cin>>x>>y>>z;

    int equal=0, nonequal=0;
    if(x==y){
        equal=x;
        nonequal=z;
    }
    else if(y==z){
        equal=y;
        nonequal=x;
    }
    else if(x==z){
        equal=z;
        nonequal=y;
    }
    
    if(equal==0){
        cout<<"NO"<<endl;
        return;
    }

    int maxi=max(x,max(y,z));
    if(maxi>equal){
        cout<<"NO"<<endl;
        return;
    }

    else{
        cout<<"YES"<<endl<<maxi<<" "<<nonequal<<" "<<nonequal<<endl;
        return;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}