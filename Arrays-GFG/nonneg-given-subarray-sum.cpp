#include<bits/stdc++.h>
//find sub array with given sum on non neg array

using namespace std;

int main(){
	int n, k;
	cin>>n>>k;
	int * arr=new int [n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	int cur_sum=0;
	int index=0;
	
	for(int i=0; i<n; i++){
		cur_sum+=arr[i];
		if(cur_sum==k){
			cout<<"sum found at "<<i<<", "<<index<<endl;
			break;
		}
		if(cur_sum>k){
			while(cur_sum>k){
				cur_sum-=arr[index];
				index++;
			}
		}
	}
	
	



}
