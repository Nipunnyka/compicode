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

void solve(){
    int n;
    string a,b;
    FAST;
    cin>>n>>a>>b;
    cout<<a<<" "<<b<<endl;
    vi moves;
    if(a==b)
    {
        cout<<0<<endl;
        return;
    }

    bool reverse=true;

    for(int i=n-1; i>=0; i--){
        int j=n-i-1; //for b;
        if(!a[i]==b[j]){
            std::cout<<"continue"<<endl;
            continue;
        }
        else{
            int temp=i;
            for(auto &e: a){
                if(e!=b[temp]){
                    reverse=false;
                    break;
                }
                temp--;
            }
            if(reverse){
                moves.pb(i+1);
                break;
            }
            char wanted=(b[j]=='0'?'1':'0');
            char not_wanted=b[j];
            if(a[j]==not_wanted){
                //reverse till i
                moves.pb(i+1);
                string t=a.substr(0,i+1);
                int k=i;
                for(auto &e: t) 
                {   a[k]=!e;
                    k--;
                }
            }
            else if(a[j]==wanted){
                //twice reverse till i-1
                
                //find first !wante
                int k;
                for(int k=i; k>=0; k--){
                    if(a[k]==wanted)
                        break;
                }
                moves.pb(k+1);
                string t=a.substr(0,k+1);
                int m=k;
                for(auto &e: t) 
                {   a[m]=!e;
                    m--;
                }

                moves.pb(i+1);
                t=a.substr(0,i+1);
                k=i;
                for(auto &e: t) 
                {   a[k]=!e;
                    k--;
                }

                
            }
        }
    }
    if(!reverse){
        moves.pb(n);
    }
    cout<<moves.size()<<" ";
    for(auto &e: moves)
        cout<<e<<" ";
    cout<<endl;
    return;

}

int main(){
    int t;
    FAST;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}