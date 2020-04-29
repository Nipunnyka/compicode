#include<bits/stdc++.h>

using namespace std;

/*
 * The cost of a stock on each day is given in an array, find the max profit that
you can make by buying and selling in those days

 * Approach:
 *  find local minima and maxima and suctract
 */
 
#define pb push_back
#define mp make_pair
#define fi first 
#define se second
int max_prof(int * arr, int n){
	
	vector<pair<int, int>> minima, maxima;
	for(int i=0; i<n; i++){;
			cout<<arr[i]<<" ";
		}
	
	int ans=0;
	
	for(int i=0; i<n; i++){
		if((i==0 && arr[i]<arr[i+1]) || (arr[i-1]>=arr[i] && arr[i+1]>arr[i]))
			minima.pb(mp(arr[i], i));
		if((i==n-1 && arr[i]>arr[i-1]) || (arr[i-1]<=arr[i] && arr[i+1]<arr[i]))
			maxima.pb(mp(arr[i], i));
	}
	//in case of decreasing order both vector will be empty
	//here i am assuming i wont but shitbut if its necessary to buy subtract nearest pairs
	if(minima.size()==0 || maxima.size()==0 ){
		return 0;
	}
	
	vector<pair<int, int>>::iterator it1, it2;
	it1=minima.begin();
	it2=maxima.begin();
	if((*it1).second<=(*it2).second){
		//price is like MMM begin making pairs with first index of it1
		for( ; (it1!=minima.end() || it2!=maxima.end()); it1++, it2++){
			ans+=((*it2).fi-(*it1).fi);
		}
	}
	else {
		//ths is like WW
		it2++;
		for( ; (it1!=minima.end() || it2!=maxima.end()); it1++, it2++){
			ans+=((*it2).fi-(*it1).fi);
		}
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int price[100];
		int n;
		cin>>n;
		for(int i=0; i<n; i++){;
			cin>>price[i];
		}
		int soln=max_prof(price, n);
		cout<<soln<<endl;
	}
	return 0;
}
