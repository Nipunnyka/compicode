#include<bits/stdc++.h>

using namespace std;

string getString(char c){
    string s(1, c);
    return s;
}


////////************STRING TEMP END*************/////////////

void removeUtil(char *s, int n, string &ans, char lastRemoved){
    if(n==0){
        cout<<ans<<endl;
        return;
    }

    if(s[0]==lastRemoved){
        s++;
        removeUtil(s, n-1, ans, lastRemoved);
    }
    else if(s[0]==s[1] && n>1){
        lastRemoved=s[0];
        s++; s++;
        removeUtil(s, n-2, ans, lastRemoved);
    }
    else if(ans[ans.size()-1]==s[0]){
        lastRemoved=s[0];
        s++;
        ans.erase(ans.size()-1, 1);
        removeUtil(s, n-1, ans, lastRemoved);
    }
    else{
        ans.append(getString(s[0]));
        s++;
        removeUtil(s, n-1, ans, lastRemoved);
    }

}

void solve(){
    string s,ans;
    cin>>s;
    char* str=const_cast<char *>(s.c_str());
    char c=0;
    removeUtil(str, s.size(), ans, c);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}