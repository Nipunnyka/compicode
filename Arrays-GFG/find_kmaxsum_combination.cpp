#include<bits/stdc++.h>
 using namespace std;
 #define mp make_pair
 #define se second
 #define fi first
  int main(){
	 int ar1[100]={0};
	 int ar2[100]={0};
	 int n, m,k; cin>>n>>m>>k;
	 for(int i=0; i<n; i++){
		 cin>>ar1[i];
	 }
	 for(int i=0; i<m; i++){
		 cin>>ar2[i];
	 }
	 set<pair<int, int> > my_set;
	 sort(ar1, ar1+n);
	 sort(ar2, ar2+n);
	 my_set.insert(make_pair(n-1, m-1));
	 priority_queue <pair<int, pair<int, int>>> pq;
	 pq.push(mp(ar1[n-1]+ar2[m-1], mp(n-1, m-1)));
	 int i, j;
	 while(k--){
		 pair<int, pair<int, int>> temp = pq.top();
		 pq.pop();
		 cout<<temp.first<<endl;
		 i=temp.se.fi;
		 j=temp.se.se;
		 pair<int, int> temp1 = make_pair(i - 1, j);
		 if (my_set.find(temp1) == my_set.end()) {
			pq.push(make_pair(ar1[i-1]+ar2[j], temp1));
			my_set.insert(temp1);
		 }
		 temp1 = make_pair(i, j - 1);
		 if (my_set.find(temp1) == my_set.end()) {
		 pq.push(make_pair(ar1[i]+ar2[j-1], temp1));
		 my_set.insert(temp1);
		 }
	 }
	 
	 
	 
	 
	 return 0;
 }

