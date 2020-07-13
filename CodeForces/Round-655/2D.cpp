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

    ll k=(n-1)/2;
    vl arr(n);
    for(ll i=0; i<n; i++)
        cin>>arr[i];
    sort(arr.begin(), arr.end());
    ll ans=0, i=0;
    for(auto it=arr.begin(); it!=arr.end(); it++, i++){
        if(i<k)
            continue;
        else{
            ans+=ptr;
        }
    }
    cout<<ans<<endl;
    return 0;

}

