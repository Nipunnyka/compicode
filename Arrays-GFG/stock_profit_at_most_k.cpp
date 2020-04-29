#include<bits/stdc++.h>

using namespace std;

int atmostk(int price[], int n, int  k){
	int **profit= new int*[k+1];
	for(int i = 0; i <=k; ++i)
		profit[i] = new int[n+1];
	for(int i=0; i<k+1; i++)
		profit[i][0]=0;
	for(int i=0; i<n+1; i++)
		profit[0][i]=0;
	int maxdiff=INT_MIN;
	//maxdiff represents the profit till that day plus the cost of buying the stock on tht day
	for(int i=1; i<k+1; i++){
		for(int j=1; j<n+1; j++){
			maxdiff=max(maxdiff, profit[i-1][j-1]-price[j-1]);
			profit[i][j]=max(profit[i][j-1], maxdiff+price[j]);
		}
	}
	return profit[k][n-1];
}



int main(){
	int t;
	cin>>t;
	while(t--){
		
		int arr[100];
		int n,k;
		cin>>n>>k;
		
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		
		int maxd=atmostk(arr, n, k);
		cout<<maxd<<endl;
		
	}	
	return 0;
}
