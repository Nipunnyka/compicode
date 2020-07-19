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
    string s;
    int n;
    vi pos_val;
    cin>>s>>n;
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        pos_val.pb(t);
    }

    unordered_map<char, int> umap;
    vector<pair<char, int>> sorted_char;

    for(auto &e: s){
        if(umap.find(e)==umap.end()){
            umap[e]=1;
            sorted_char.pb(mp(e,0));
        }
        else if(umap.find(e)!=umap.end()){
            umap[e]++;
        }
    }

    sort(sorted_char.begin(), sorted_char.end());
    int sorted_char_size=sorted_char.size();
    sorted_char[sorted_char_size-1].se=0;
    for(int i=sorted_char_size-2; i>=0; i--){
       sorted_char[i].se=sorted_char[i+1].se+umap[sorted_char[i+1].fi];
    }

    for(auto &e: sorted_char)
        cout<<e.fi<<": "<<e.se<<endl;

    vector<int> sorted_pos_val=pos_val;
    sort(sorted_pos_val.begin(), sorted_pos_val.end());

    unordered_map<int, vi> pos_map;

    for(int i=0; i<n; i++){
        pos_map[pos_val[i]].pb(i);
    }

    char ans[51];
    int pos_idx=0;
    set<int> placed_pos;
    int next_pos=0;
    bool moved_ahead=false;
    for(int i=sorted_char_size-1; i>=0; i--){
        int t=sorted_char[i].se;
        char c=sorted_char[i].fi;
        while(t>0){
            //find first available pos in posmap
            int map_pos, k=0;
            for(auto it=pos_map[sorted_pos_val[pos_idx]].begin(); it!=pos_map[sorted_pos_val[pos_idx]].end(); it++, k++){
                if(ptr!=-1 && placed_pos.find(ptr)==placed_pos.end()){
                    map_pos=ptr;
                    break;
                }
            }

            if(placed_pos.size()==0)
            {
                ans[map_pos]=c;
                pos_idx++;
                pos_map[sorted_pos_val[pos_idx]][k]=-1;
                t--;
                placed_pos.insert(map_pos);
            }
            else{
                int tot=0;
                for(auto &e: placed_pos){
                    if(ans[e]>c){
                        tot+=abs(e-map_pos);
                    }
                }
                if(tot==sorted_pos_val[pos_idx]){
                    ans[map_pos]=c;
                    pos_idx++;
                    pos_map[sorted_pos_val[pos_idx]][k]=-1;
                    t--;
                    placed_pos.insert(map_pos);
                    if(moved_ahead){
                        pos_idx=next_pos;
                        moved_ahead=false;
                    }
                }
                else{
                    if(moved_ahead==false)
                    {
                        next_pos=pos_idx;
                        pos_idx++;
                        moved_ahead=true;
                    }
                    else{
                        pos_idx++;
                    }
                }
            }
            
        }
    }
    for(int i=0; i<n; i++){
        cout<<ans[i];
    }
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
