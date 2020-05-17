#include<bits/stdc++.h>
using namespace std;
int arr[1000000];
int tmp, t;
int main(){
    cin>>t;
    tmp=t;
    while(t--){
        int n, k;
        cin>>n>>k;
        for(int i=0; i<n; i++)
            cin>>arr[i];
        int w=k, count =0;
        bool flag=false;
        for(int i=0; i<n; i++){
			if(arr[i]==k){
				w=k-1;
				flag=true;
			}
			else if(flag&&arr[i]==w){
				--w;
				if(arr[i]==1){
					count++;
				}
			}
			else{
			w=k;
			flag=false;
			}
		}
    
    cout<<"Case #"<<tmp-t<<": "<<count<<endl;
	}
    return 0;
}

