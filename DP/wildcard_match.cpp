#include<bits/stdc++.h>

using namespace std;


bool isMatch(string s, string p) {
    int l1= s.length();
    int l2=p.length();
    int ** dp= new int*[l1+1];
    
    for(int i=0; i<=l1; i++)
    {
        dp[i]=new int[l2+1];
        dp[i][0]=0;
    }
    for(int i=0; i<=l2; i++){
        dp[0][i]=0;
    }
    dp[0][0]=1;
    
    for(int i=1; i<=l1; i++){
        for(int j=0; j<=l2; j++){
            //i i string
            //j i spattern
            if(s[i-1]==p[j-1] || p[j-1]=='?'){
                dp[i][j]=dp[i-1][j-1];
            }
            else if(p[j-1]=='*'){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j]+dp[i][j-1];
            }
            else 
                dp[i][j]=0;
        }
    }
    if(dp[l1][l2])
        return true;
    else
        return false;
    
    
}


int main(){
	string s="aaabcdgh";
	string p="a*bc*d??";
	
	bool ans=isMatch(s, p);
	cout<<ans<<endl;
	
	return 0;
}
