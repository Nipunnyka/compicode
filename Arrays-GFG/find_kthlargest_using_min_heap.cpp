#include<bits/stdc++.h>
 using namespace std;
 
 int main(){
	 int arr[100]={0};
	 int n,k; cin>>n>>k;
	 for(int i=0; i<n; i++){
		 cin>>arr[i];
	 }
	 priority_queue <int, vector<int>, greater<int>> minheap;
	 
	 int p=0;
	 while(p<n){
		 while(minheap.size()<k){
			  minheap.push(arr[p]);
			  p++;
		}
		if(minheap.size()==k){
			if(arr[p]<minheap.top())
				p++;
			else
			{
				minheap.pop();
				minheap.push(arr[p]);
				p++;
			}
		}
	 }
	 cout<<minheap.top();
	 
	 
	 
	 
	 return 0;
 }
