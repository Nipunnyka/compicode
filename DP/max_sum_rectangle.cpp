#include <bits/stdc++.h>

using namespace std;
pair<int, pair<int, int>> findkadane( int *arr, int n){
	int cursum=0, maxsum=INT_MIN, left=-1, right=-1, curstart=0;
	for(int i=0; i<n; i++){
		cursum+=arr[i];
		if(cursum<0){
			cursum=0;
			curstart=i;
		}
		if(cursum >maxsum){
			maxsum=cursum;
			right=0;
			left=curstart;
		}	
	}
	pair<int, pair<int, int>> p=make_pair(maxsum, make_pair(left, right));
	return p;
}

int main(){
	int rect[1000][1000]={0};
	
	int row, col;
	cin>>row>>col;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++)
			cin>>rect[i][j];
	}
	
	int * kadane= new int[row];
	int cursum=0, maxsum=INT_MIN, leftarr=0, rightarr=0, uparr, downarr;
	for(int left=0; left<col; left++){
		//clear kadane array
		for(int k=0; k<row; k++)
			kadane[k]=0;
		for(int right=left; right<col; right++){
			for(int vertical=0; vertical<row; vertical++){
				//put sum in kadane, find cursum
				kadane[vertical]+=rect[right][vertical];
			}
			//update max, left, right, up, down
			pair<int,pair<int, int>> p;
			p=findkadane(kadane, row);
			cursum=p.first;
			cout<<"curcum: "<<cursum<<endl;
			if(cursum>maxsum){
				maxsum=cursum;
				uparr=p.second.first;
				downarr=p.second.second;
				leftarr=left;
				rightarr=right;
				cout<<"iam changig leftarr to "<<leftarr<<endl;
			}
			
		}
	}
	cout<<uparr<<" "<<downarr<<" "<<leftarr<<" "<<rightarr<<endl;
	
	cout<<"maxsum is "<<maxsum<<endl;
	for(int i=uparr; i<downarr; i++){
		for(int j=leftarr; j<rightarr; j++){
			cout<<rect[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
