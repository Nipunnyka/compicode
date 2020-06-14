#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<int> v={0,2,4,5,1,3};
	int n=v.size();
	vector<int> visited(n);
	int ans=0;
	for(int i=1; i<n; i++){
		if(!visited[v[i]] && v[i]!=i){
			int j=i;
			int cycle_size=0;
			while(!visited[v[j]]){
				cycle_size++;
				cout<<"i am inc for"<<v[j]<<endl;
				visited[v[j]]=1;
				j=v[j];
			}
			if(cycle_size){
				ans+=cycle_size-1;
			}
		}
		
		
	}
	cout<<ans<<endl;
	
	return 0;
}
