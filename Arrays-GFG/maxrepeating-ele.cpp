/*Find the maximum repeating number in O(n) time and O(1) extra space​ :-
Given an array of size n, the array contains numbers in range from 0 to k-1
where k is a positive integer and k <= n. Find the maximum repeating number in
this array. For example, let k be 10 the given array be arr[] = {1, 2, 2, 2,
0, 2, 0, 2, 3, 8, 0, 9, 2, 3}, the maximum repeating number would be 2.
Expected time complexity is O(n) and extra space allowed is O(1).
Modifications to array are allowed.*/

//if there are more than one max repeating element it prints the biggest one 

#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n, k;
	cin>>n>>k;
	int * arr= new int [n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
		
	//the index of the value which is repeated most will be incremented maximum times
	for(int i=0; i<n; i++){
		arr[arr[i]%k]+=k;
	}
	int maxi=INT_MIN, index=0;
	for(int i=0; i<n; i++){
		maxi=max(maxi, arr[i]);
		index=i;
	}
	
	cout<<maxi%k<<endl;
	
	return 0;
}
