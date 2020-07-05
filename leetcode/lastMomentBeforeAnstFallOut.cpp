#include <iostream>
#include<bits/stdc++.h>
#define fi first
#define se second
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define ptr (*it)
using namespace std;


class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxval=INT_MIN;

        for(auto &e: left){
            maxval=max(maxval, e);
        }
        for(auto &e: right){
            maxval=max(maxval, n-e);
        }

    return maxval;
    }
};

int main(){
    vector<int> left={0,1,2,3,4,5,6,7};
    vector<int> right={};
    int n=7;
    Solution *s=new Solution();
    int ans=(*s).getLastMoment(n, left, right);
    cout<<ans<<endl;
    return 0;
}