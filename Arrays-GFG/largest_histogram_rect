#include<bits/stdc++.h>

using namespace std;
int largestRectangleArea(vector<int>& heights) {
	
		int n = heights.size();
		if (!n) return 0;
        
        heights.push_back(0);
        stack<int>stk;
		int res = 0;
		
		for (int i = 0; i < heights.size(); i++) {
			while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int h = heights[stk.top()];
                stk.pop();
                int l = stk.empty() ? 0 : stk.top()+1;
                res = max(res, (i-l)*h);
			}
			stk.push(i);
		}
        
		return res;
  }

int main(){
	vector<int> height={1,2,3,4,5,3,3,2,1};
	int ans= largestRectangleArea(height);
	cout<<ans;
	
	return 0;
}
