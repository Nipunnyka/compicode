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
    int n,x,m;
    cin>>n>>x>>m;
    pi set_bit_range;
    set_bit_range.fi=x;
    set_bit_range.se=x;

    for(int i=0; i<m; i++){
        int l, r;
        cin>>l>>r;
        //check if l r range overlaps with set bit range
        if(max(set_bit_range.fi, l)<=min(set_bit_range.se, r)){
            set_bit_range.fi=min(set_bit_range.fi, l);
            set_bit_range.se=max(set_bit_range.se,r);
        }
    }
    cout<<set_bit_range.se-set_bit_range.fi+1<<endl;
    return;
}

int main(){
    FAST;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}