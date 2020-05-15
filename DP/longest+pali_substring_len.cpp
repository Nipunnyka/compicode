#include<bits/stdc++.h>

using namespace std;

int dp[1000][1000]={0};

int longestPalindrome(string s) {
        int n=s.length();
        /*int **dp=new int* [n];
        for(int i=0; i<n; i++){
            dp[i]=new int [n];
        }*/
        for(int i=0; i<n; i++){
            dp[i][i]=1;
        }
        
        //for length 2
        for(int i=0; i<n-1; i++){
            if(s[i]==s[i+1])
                dp[i][i+1]=2;
        }
        
        for(int l=3; l<=n; l++){
            for(int i=0; l<=n-l+1; i++){
				
					if(s[i]==s[i+l-1]&&dp[i+1][i+l-2]>=l-2){
						dp[i][i+l-1]=l;
					}
					else{
						dp[i][i+l-1]=max(dp[i+1][i+l-1], dp[i][i+l-2]);
					}
				
            }
        }
        cout<<"check: "<<dp[1][3]<<endl;
        for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
        return dp[0][n-1];
        
 }
 
 int main(){
	 int t; cin>>t;
	 while(t--){
	 string s;
	 cin>>s;
	 int ans=longestPalindrome(s);
	 cout<<ans<<endl;
	}
	 return 0;
 }
