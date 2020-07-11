#include <iostream>
#include<bits/stdc++.h>

using namespace std;
int arr[1000000]={0};

void solve(){
    int n ;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    //cout<<"out of loo";
    int num=0;
    for(int i=1; i<=n; i++){
        if(arr[i]<0){
            continue;
        }
        int* next=&arr[arr[i]];
        arr[i]=arr[i]*(-1);
        bool flag=false;
        while(*next>0){
            (*next)=(*next)*-1;
            *next=arr[(*next)*-1];
            flag=true;
        }
        if(flag)
            num++;
    }
    cout<<num<<endl;
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}