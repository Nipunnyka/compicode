
#include<bits/stdc++.h>
#define fi first
#define se second
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define ptr (*it)
#define ll long long

#define INT_MAX __INT_MAX__
using namespace std;


#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


void solve(){
    FAST;
    ll n;
    cin>>n;
    
    bool flag=false;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            flag=true;
            cout<<(n/i)<<" "<<(n-(n/i))<<endl;
            return;
        }
    }
    if(flag==false){
        cout<<1<<" "<<n-1<<endl;
        return;
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}