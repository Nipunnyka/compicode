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
    FAST;
    int v[100];
    cin>>n;
    int bad_even=0, bad_odd=0;
    for(int i=0; i<n; i++)
    {   
        cin>>v[i];
        int t=v[i]%2;
        if(i%2==0&&t==1)
            bad_odd++;
        else if(i%2==1&&t==0)
            bad_even++;
    }
    if(bad_even!=bad_odd){
        cout<<-1<<endl;
        return;
    }
    else{
        cout<<(bad_odd)<<endl;
        return;
    }
}

int main(){
    int t;
    FAST;
    cin>>t;
    while(t--){
        solve();
    }
}