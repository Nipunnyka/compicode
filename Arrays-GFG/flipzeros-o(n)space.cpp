//Find zeroes to be flipped so that number of consecutive 1’s is maximized

//Input: arr, m is max zeros to be flipped
#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	int *arr=new int [n];
	
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	int * right =new int [n];
	int * left =new int [n];
	vector<int> zeros;
	int count=0;
	for(int i=0; i<n; i++){
		if(arr[i]==1)
			count++;
		else if(arr[i]==0){
			zeros.push_back(i);
			left[i]=count;
			count =0;
		}
	}
	count =0;
	for(int i=n-1; i>=0; i--){
		if(arr[i]==1)
			count++;
		else if(arr[i]==0){
			//zeros.push_back(i);
			right[i]=count;
			count =0;
		}
	}
	
	vector<int>::iterator it=zeros.begin();
	while(it!=zeros.end()){
		cout<<"at index "<<*it<<" left: "<<left[*it]<<" and right: "<<right[*it]<<endl;
		it++;
	}
	

	return 0;
}
