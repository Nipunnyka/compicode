//problem: https://codeforces.com/problemset/problem/1374/D
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
using namespace std::chrono; 
using namespace std;
auto start = high_resolution_clock::now();
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> arr(n);
        unordered_map<ll, int> m;
        int maxocc=0;
        int maxindex=0;
       
        for(ll i=0; i<n; i++){
            ll c;
            cin>>c;
            arr.pb(c);
            //cout<<"inputted "<<t<<endl;
            ll t=(((c/k)+1)*k)-c;
            if(c%k!=0){
                m[t]++;
                if(m[t]>maxocc){
                    maxocc=m[t];
                    maxindex=t;
                }
                if(m[t]==maxocc&&t>maxindex){
                    maxindex=t;
                }
            }
        }
        
        //find steps to reach one instance maxindex
        ll steps=0;
        if(maxocc==0){
            cout<<"0"<<endl;
            continue;
        }
        else{
            steps=1+maxindex;
            steps+=(maxocc-1)*k;
            cout<<steps<<endl;
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); 
    cout <<"time taken: "<<duration.count() << endl; 
    
    return 0;
}