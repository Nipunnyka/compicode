#include <bits/stdc++.h>
/*in:1
     4
     3 9 1 2

 * every value in table is correct except the dp[0][l-1] its supposed to be 11 its 12 idk how
 * 
 */
using namespace std;

struct p{
	int fi;
	int se;
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int l;
		cin>>l;
		int * arr=new int[l];
		for(int i=0; i<l; i++)
			cin>>arr[i];
		p **dp=new p*[l];
		for(int i=0; i<l; i++){
			dp[i]=new p[l];
			dp[i][i].fi=arr[i];
			dp[i][i].se=0;
		}
		//int len=2;
		for(int i=0; i<l-1; i++){
			dp[i][i+1].fi=max(arr[i], arr[i+1]);
			dp[i][i+1].se=min(arr[i], arr[i+1]);
		}
		for(int len=3; len<l; len++){
			for(int i=0; i<len; i++){
				if(arr[i]+dp[i+1][i+len-1].se>arr[i+len-1]+dp[i][i+len-2].se){
					dp[i][i+len-1].fi=arr[i]+dp[i+1][i+len-1].se;
					dp[i][i+len-1].se=dp[i+1][i+len-1].fi;
				}
				else{
					dp[i][i+len-1].fi=arr[i+len-1]+dp[i][i+len-2].se;
					dp[i][i+len-1].se=dp[i][i+len-2].fi;
				}
				//cout<<"Added "<<dp[i][i+len-1].fi<<" ";
			}
		}
		if(arr[0]+dp[0][l-2].se>arr[l-1]+dp[1][l-1].se){
			dp[0][l-1].fi=arr[0]+dp[0][l-2].se;
			dp[0][l-1].se=dp[0][l-2].fi;
			cout<<"	change"<<endl;
		}
		else{
			dp[0][l-1].fi=arr[l-1]+dp[1][l-1].se;
			dp[0][l-1].se=dp[1][l-1].fi;
		}
		for(int i=0; i<l; i++){
			for(int j=0; j<l; j++){
				cout<<dp[i][j].fi<<", "<<dp[i][j].se<<" ";
			}
			cout<<endl;
		}
		int ans=dp[0][l-1].fi;
		cout<<"ans "<<arr[0] <<endl;
	}
	
	return 0;
}
