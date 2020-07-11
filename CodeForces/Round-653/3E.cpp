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
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



using namespace std::chrono; 
using namespace std;

vector<int> merge(vector<int> &a, vector<int> &b){
    //given a>b
    int i;
    vector<int> merged(b.size());
    for(i=0; i<b.size(); i++){
        //i --b and j--a
        merged[i]=b[i]+a[i];
    }
    
    return merged;
}

ll mergek(vector<int>&a, vector<int>&b, ll k){

    int i=0,j=0,c=0;
    ll tot=0;
    bool flaga=false, flagb=false;
    while(c<k && flagb==false && flaga==false){
        if(a[i]<b[j]){
            tot+=a[i];
            i++;
            if(i==a.size()){
                flaga=true;
            }
        }
        else{
            tot+=b[j];
            j++;
            if(j==b.size()){
                flagb=true;
            }
        }
        c++;
    }
    if(flaga && c<k){
        while(c<k &&j<b.size()){
            tot+=b[j];
            j++;
        }
    }
    else if(flagb && c<k){
        while(c<k &&i<a.size()){
            tot+=a[i];
            i++;
        }
    }
    return tot;
}

void solve(){
    int n, k, i;
    cin>>n>>k;
    vector<int> a, b, anb;
    for(i=0; i<n; i++){
        int time, alike, blike;
        cin>>time>>alike>>blike;

        if(alike*blike==1){
            anb.pb(time);
        }
        else if(alike==1 and blike==0)
            a.pb(time);
        else if(blike==1 and alike==0)
            b.pb(time);
    }

    //no solution case
    if(a.size()+anb.size()<k || b.size()+anb.size()<k){
        cout<<"-1"<<endl;
        return;
    }
    vector<int> mergeab;
    
    //merge a b
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(anb.begin(), anb.end());
    

    if(a.size()>b.size()){
        mergeab=merge(a,b);
    }
    else
        mergeab=merge(b,a);
    //merge both arrs k times;
    ll ans=0;
    if(mergeab.size()==0){
        int count=0; ll tot=0;
        for(auto &e:anb){
            if(count<k){
                ans+=e;
                count++;
            }
            else 
                break;
        }
        if(count<k)
        {
            cout<<"-1"<<endl;
            return;
        }
    }
    else if(anb.size()==0){
        int count=0; ll tot=0;
        for(auto &e:mergeab){
            if(count<k){
                ans+=e;
                count++;
            }
            else 
                break;
        }
        if(count<k)
        {
            cout<<"-1"<<endl;
            return;
        }
    }
    else
        ans=mergek(mergeab, anb, k);
    cout<<ans<<endl;
    
    return;
}


int main(){
    solve();
}