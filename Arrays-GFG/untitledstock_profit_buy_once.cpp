#include<bits/stdc++.h>

using namespace std;

//#define ll long long

//Maximum difference between two elements such that larger element appears after the smaller number

int max_diff(int * v, int n){
	int minsofar=v[0];
	int maxd=INT_MIN;
	
	for(int i=1; i<n; i++)
	{
		int d=v[i]-minsofar;
		if(d>maxd)
			maxd=d;
		if(v[i]<minsofar)
			minsofar=v[i];
	}
	return maxd;
	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		
		int arr[100];
		int n;
		cin>>n;
		
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		
		int maxd=max_diff(arr, n);
		cout<<maxd<<endl;
		
	}	
	return 0;
}
