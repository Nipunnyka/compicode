#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000]={0};
int tmp, t;
int main(){

    cin>>t;
    tmp=t;
    while(t--){
        int n, k, p;
        int
        int **s=new int*[n];
        for(int i=0; i<k; i++){
            s[i]=new int[k];
            s[i][0]=0;
        }
        for(int i=0; i<n; i++){
            for(int j=1; j<=p; j++){
                int c=0;
                for(int c=0; i<min(j, k); c++){
                    dp[i][j]=max(dp[i][j], s[i][c]+dp[i-1][j-c]);
                }
            }
        }
        cout<"case #"<<(tmp-t+1)<<dp[0][p];
    }
    return 0;
}
