#include<bits/stdc++.h>
#define fi first
#define se second
#define pi pair<int, int>
#define pb push_back

#define mp make_pair
#define ptr (*it)
#define ll long long
#include <chrono> 

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std::chrono; 
using namespace std;

void solve(){
    int a,b;
    FAST;
    cin>>a>>b;
    cout<<min(a,min(b,(a+b)/3))<<endl;
    return;
}

int main(){
    int t;
    FAST;
    cin>>t;
    while(t--){
        solve();
    }
}