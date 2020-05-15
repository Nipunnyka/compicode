#include <bits/stdc++.h>

using namespace std;

int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);
    
    const int n=nums.size();
    int dp[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dp[i][j]=0;
        }
    }
    
    for(int i=1; i<n-1; i++){
        dp[i][i]=nums[i]*nums[i-1]*nums[i+1];
        //cout<<i<<" ";
    }
    
    for(int l=2; l<=n-2; l++){
        for(int left=1; left<n-l; left++){
            int right=left+l-1;
            for(int i=left; i<=right; i++){
                //cout<<left<<", "<<right<<", "<<i<<endl;
                dp[left][right]=max(dp[left][right], nums[i]*nums[left-1]*nums[right+1]+dp[i+1][right]+dp[left][i-1]);
            }
        }
    }
    return dp[1][n-2];
}

int main(){
	
	vector <int> v={5, 1, 3, 8};
	int ans=maxCoins(v);
	cout<<ans;
	
	return 0;
}
