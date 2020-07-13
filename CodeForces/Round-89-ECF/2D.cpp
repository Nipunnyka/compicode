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

ll upperbound=10000000; //10 mil up, perhaps right

vl primes;

//slice a vector
template <typename T> 
vector<T> slicing(vector<T> const& v, int X, int Y) 
{ 
    // Begin and End iterator 
    auto first = v.begin() + X; 
    auto last = v.begin() + Y + 1; 
  
    // Copy the element 
    vector<T> vector(first, last); 
  
    // Return the results 
    return vector; 
} 

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

pl primeFactors(ll n){
    
    ll pf_index=0;
    ll pf=primes[pf_index];
    ll one=1, two=1;
    bool flag=false;
    ll copyn=n;
    while(pf*pf<n){
        int count=0;
        while(n%pf==0){
            if(n==copyn)
                flag=true;
            if(flag)
            {
                one=pf;
                flag=false;
            }
            n=n/pf;
            count++;
        }
        if(count)
            two=two*pf;
        pf=primes[++pf_index];
    }
    if(n!=1)
        two=two*n;
    if(one==1)
        return mp(-1,-1);
    two=two/one;
    if(two==1)
        return mp(-1,-1);
    return mp(one,two);
}

int main(){
    primes=Sieve(upperbound);
    /*vector<pair<ll, int>> factors=primeFactors(2147483647);
    for(auto &e: factors){
        cout<<e.fi<<": "<<e.se<<endl;
    }*/
    int n;
    FAST;
    cin>>n;
    vl arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<pl> ans;
    for(auto &e: arr){
        pl temp=primeFactors(e);
        ans.pb(temp);
    }

    for(auto &e: ans)
        cout<<e.fi<<" ";
    cout<<endl;
    for(auto &e: ans)
        cout<<e.se<<" ";
    cout<<endl;
    return 0;
}