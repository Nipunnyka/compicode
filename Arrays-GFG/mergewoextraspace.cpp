#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t, k;
int main(){
	cin>>t;
	k=t;
	
    while(t--){
        ll n, d, largest, curlarge;
        cin>>n>>d;
        largest=d;
        ll * arr= new ll[n];
        for(ll i=0; i<n; i++){
            cin>>arr[i];
            //cout<<arr[i]<<" ";
        }
        for(ll i=n-1; i>=0; i--){
            curlarge=(largest/arr[i])*arr[i];
            largest=min(largest, curlarge);
            //cout<<largest<<endl;
            //now find the nearest multiple close to largest
            arr[i]=(largest/arr[i])*arr[i];
        }
        cout<<"Case #"<<k-t<<": "<<arr[0];
        /*for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }*/
        cout<<endl;
    }
    return 0;
}
