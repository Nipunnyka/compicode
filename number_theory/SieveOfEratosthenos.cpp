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
#include <cmath>
#include <iostream>

using namespace std;

vector<ll> Sieve(ll n){
    int i,j;
    vector<ll> candidates(n+1, 1);
    candidates[0]=candidates[1]=0;
    for(i=2; i*i<=n; i++){

        if(candidates[i]){
            for(j=i*i; j<=n; j+=i){
                candidates[j]=0;
            }
        }
    }
    vector<ll> ans;
    for(int i=0; i<=n; i++){
        if(candidates[i]){
            ans.pb(i);
        }
    }
    return ans;
}



int main(){
    ll n=100;
    vector<ll> primes;
    primes=Sieve(n);
    for(auto &e: primes){
        cout<<e<<" ";
    }
    cout<<endl;
    return 0;
}