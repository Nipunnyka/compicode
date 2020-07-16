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

int kmp(string s, string p){
    vector<int> table(p.size());
    //build table
    int i=0, j=0;
    table[0]=0;
    for(j=1; j<p.size(); j++){
        if(p[i]==p[j]){
            i++;
            table[j]=i;
        }
        else{
            if(i==0){
                table[j]=0;
            }
            else{
                i=table[i-1];
            }
        }
    }

    for(int i=0, j=0; i<s.size(); i++){
        if(s[i]==p[j]){
            j++;
            if(j<p.size())
                continue;
            else
                return i-p.size()+1;
        }
        else{
            if(j>0)
                j=table[j-1];
        }
    }
    return -1;

}

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s, p;
        FAST;
        cin>>s>>p;

        int pos=kmp(s,p);
        cout<<pos<<endl;
    }
    return 0;
}