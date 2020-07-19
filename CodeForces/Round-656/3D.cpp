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

int util(string s, char c){
    int n=s.size();
    if(n==1){
        if(s[0]==c)
            return 0;
        else 
            return 1;
    }
    string left=s.substr(0, n/2);
    string right=s.substr(n/2+1, n);
    int k=0;
    while(n>0){
        n=n/2;
        k++;
    }

    int last=(int)c+k;

    int left_c=0, left_valid=0, right_c=0, right_valid=0;
    for(auto &e: left){
        if(e==c)
            left_c++;
        else if((int)e<last && (int)e>(int)c)
            left_valid++;
    }

    for(auto &e: right){
        if(e==c)
            right_c++;
        else if((int)e<last && (int)e>(int)c)
            right_valid++;
    }

    return k;
}



void solve(){
    int n;
    string s;
    cin>>n>>s;
    char c='a';
    //cout<<(int)c;
    //int ans=util(s, c);
    //cout<<ans<<endl;
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