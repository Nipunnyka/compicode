#include<bits/stdc++.h>

using namespace std;

int main(){
    int t, k;
    
    cin>>t;
    k=t;
    while(t--){
        int arr[101]={0};
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int peaks=0;
        for(int i=1; i<n-1; i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) ++peaks;
        }
        cout<<"Case #"<<k-t<<": "<<peaks<<endl;
    }
    return 0;
}
