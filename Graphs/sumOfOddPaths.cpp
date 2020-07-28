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
#define pi pair<int, int>
#define vpi vector<pi>
#define mp make_pair
#define pb push_back
#define fi first 
#define se second

using namespace std;
long long final=0;
class Graph{
	public:
	int n; 
	int m;
	vector<vpi> adj;

	Graph(int n, int m){
		this->n=n;
		this->m=m;
		vector<vpi> adj;
	}

	void inputGraph(){
		adj.resize(n);
		while(m--){
			int src, dest, wt;
			cin>>src>>dest>>wt;
			adj[src].pb(mp(dest, wt));
		}
	}

	int bfs(){
		int src=1;
		unordered_map<int, int> odd, even;
		int nodesLeft=1, nodesNext=0, level=1;
		vector<bool> vis(n, false);
		vector<int> ans;
		queue<int> q;
		q.push(src);
		while(!q.empty()){
			int front=q.front();
			q.pop();
			for(auto &e: adj[front]){
				if(!vis[e.fi])
				{
					vis[e.fi]=true;
					q.push(e.fi);
					nodesNext++;
					if(e.se%2==0)
						even[level]++;
					else
						odd[level]++;
				}
			}
			nodesLeft--;
			if(nodesLeft==0){
				nodesLeft=nodesNext;
				nodesNext=0;
				level++;
			}
			if(level>1){
				if(level%2==0){
					ans[level]=(ans[level-1]*even[level])+odd[level];
				}
				else
					ans[level]=odd[level]+(ans[level-1]*odd[level]);
			}
			else
				ans[level]=odd[level];
			final+=ans[level];
		}
		return final;
	}

};

int main(){
	int n;
	cin>>n;
	Graph g(n, n-1);
	g.inputGraph();
	//assume root is 1

    cout<<g.bfs()<<endl;

	return 0;
}
