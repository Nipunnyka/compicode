/*Given a sorted array (sorted in non-decreasing order) of positive numbers,
find the smallest positive integer value that cannot be represented as sum of
elements of any subset of given set.
Expected time complexity is O(n)*/

#include<bits/stdc++.h>

using namespace std;

int main(){
	
	//least possible number is 1 so lets starts from there
	int n;
	cin>>n;
	int *arr=new int [n];
	for(int i=0; i<n; i++) 
		cin>>arr[i];
	
	int ans=1;
	
	for(int i=0; i<n; i++){
		if(arr[i]==ans)
			ans++;
		if(arr[i]>ans)
			break;
	}
	
	cout<<"answer is"<< ans<<endl;
	
	return 0;
}
