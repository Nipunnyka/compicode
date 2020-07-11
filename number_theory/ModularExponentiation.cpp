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

ll pow_mod(ll x, ll y, ll m){
    if(y==0)
        return 1;
    ll res=1;
    
    while(y>0){
        if(y%2){
            res=(x*res)%m;
        }
        x=(x*x)%m;
        y=y/2;
    }
    return res;

}

int main(){
    ll m=mod;
    ll x=4, y=87;
    cout<<pow_mod(x, y, m)<<endl;
    return 0;
}