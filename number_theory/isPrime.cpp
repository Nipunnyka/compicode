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
const ll mod= 1000000007;

using namespace std;
const ll upperbound=1000;

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

bool isPrime(vector<ll> primes, ll key){

    if(key>2 && key%2==0){
        return false;
    }
    for(auto it=primes.begin(); it!=primes.end(), ptr<sqrt(key); it++){
        if(key%ptr==0)
            return false;
    }
    return true;
}

int main(){

    vector<ll> primes=Sieve(upperbound);
    ll n=93;

    cout<<isPrime(primes, n);

    return 0;
}