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
using namespace std;

ll upperbound=10000000; //10 mil up, perhaps right

vl primes;

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

vector<pair<ll, int>> primeFactors(ll n){
    vector<pair<ll, int>> factors;

    ll pf_index=0;
    ll pf=primes[pf_index];

    while(pf*pf<n){
        int count=0;
        while(n%pf==0){
            n=n/pf;
            count++;
        }
        if(count)
            factors.pb(mp(pf, count));
        pf=primes[++pf_index];
    }
    if(n!=1)
        factors.pb(mp(n,1));
    return factors;
}

int main(){
    primes=Sieve(upperbound);
    vector<pair<ll, int>> factors=primeFactors(2147483647);
    for(auto &e: factors){
        cout<<e.fi<<": "<<e.se<<endl;
    }
}