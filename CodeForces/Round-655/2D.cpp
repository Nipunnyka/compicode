#include<bits/stdc++.h>
#define fi first
#define se second
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define ptr (*it)
#define ll long long
#define INT_MAX __INT_MAX__
#define vl vector<ll>
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main()
{
    FAST;
    ll n;
    cin>>n;
    vl arr(n);
    
    vl odd;
    vl even;

    for(int i=0; i<n; i++){
        ll t;
        cin>>t;
        arr[i]=t;
        if(i%2==0){
            //odd pos
            odd.pb(t);
        }
        else
        {
            //even pos
            even.pb(t);
        }
        if(n==1){
            cout<<t<<endl;
            return 0;
        }
    }

    for(auto &e: odd){
        even.pb(e);
    }

    int w=(n+1)/2;
    ll tot=0;
    for(int i=0; i<w; i++)
        tot+=even[i];

    ll maxi=INT_MIN;
    ll cur=tot;
    for(int i=w; i<n; i++)
    {
        cur-=even[i-w];
        cur+=even[i];
        if(cur>tot)
            tot=cur;
    }
    cout<<tot<<endl;
    return 0;

}

