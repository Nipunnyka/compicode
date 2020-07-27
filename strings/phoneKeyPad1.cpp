/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include<bits/stdc++.h>
#define vpi vector<pair<int, int>>
#define fi first
#define se second
#define pi pair<int, int>
#define mp make_pair
#define pb push_back

using namespace std;

bool compare(const pi a, const pi b){
	if(a.se==b.se){
		return a.fi<b.fi;
	}
	return a.se>b.se;
}

int main(){
	vpi v1, v2;
	int d, n1, n2;
	cin>>d>>n1>>n2;
	for(int i=0; i<n1; i++){
		int a,b;
		cin>>a>>b;
		v1.pb(mp(a,b));
	}
	for(int i=0; i<n2; i++){
		int a,b;
		cin>>a>>b;
		v2.pb(mp(a,b));
	}

	sort(v1.begin(), v1.end(), compare);
	sort(v2.begin(), v2.end(), compare);

	auto it1=v1.begin(), it2=v2.begin();
	bool found=false;
	int ans;
	while(!found && it1!=v1.end() && it2!=v2.end()){
		ans=(*it1).se+(*it2).se;
		if(ans>d){
			if(*(it1++)>*(it2++)){
				it2--;
			}
			else{
				it1--;
			}	
		}
		else{
			found=true;
		}
	}
	if(found)
		cout<<"[["<<(*it1).fi<<", "<<(*it2).fi<<"]]"<<endl;
	else
		cout<<"[]"<<endl;
	return 0;
}
