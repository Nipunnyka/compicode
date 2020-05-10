#include <bits/stdc++.h>

using namespace std;



int minCostClimbingStairs(vector<int>& cost) {
    int n=cost.size();
    int tot=0, curcost=0;
    int *cost2=new int [n+1];
    memset(cost2, 0, sizeof(cost));
    for (int i=1; i<n+1; i++){
		cost2[i]=cost[i-1];
	}
    
    for(int i=1; i<n+1; i++){
        curcost=0;
        int mini=INT_MAX;
        for(int j=1; j<=2; j++){
            /*if(i==j){
                curcost=0;
                if(curcost<mini){
                    mini=curcost;
                    //cout<<mini<<endl;
                }
            }*/
            if(i>=j){
                curcost=cost[i-j];
                if(curcost<mini){
                    mini=curcost;
                    //cout<<mini<<endl;
                }
            }
        }
        tot+=curcost;
    }
    return tot;
}

int main(){
	
	vector<int> cost={10, 15, 20};
	int ans=minCostClimbingStairs(cost);
	cout<<ans<<endl;
	return 0;
}
