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

ll gcd(ll a, ll b){
    return b==0?a:gcd(b,a%b);
}

ll lcm(ll a, ll b){
   return a*(b/gcd(a,b));
}

int main(){
    ll a=1, b=3;
    cout<<gcd(a,b)<<" "<<lcm(a,b);
    return 0;
}