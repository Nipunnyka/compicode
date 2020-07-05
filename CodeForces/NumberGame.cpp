//
#include <iostream>
#include<bits/stdc++.h>
#define fi first
#define se second
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define ptr (*it)
#define ll long long
#include <chrono> 
using namespace std::chrono; 
using namespace std;

bool oddDivisors(int n){
    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0&& ((i%2!=0&& i>1)|| ((n/i)%2!=0&& (n/i)>1))) {
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n==1){
            cout<<"FastestFinger"<<endl;
        }
        else if(n==2){
            cout<<"Ashishgup"<<endl;
        }
        else{
            if(n%2!=0){
                cout<<"Ashishgup"<<endl;
            }
            else if(oddDivisors(n)){
                if(n%4==0){
                    cout<<"Ashishgup"<<endl;
                }
                else{
                    //check if n/2 is prime
                    ll root=sqrt(n/2);
                    bool flag=true;
                    for(int i=2; i<=root; i++){
                        if(((n/2)%i)==0){
                            cout<<"Ashishgup"<<endl;
                            flag=false;
                            break;
                        }
                    }
                    if(flag){
                        cout<<"FastestFinger"<<endl;
                    }
                }                
            }
            else{
                cout<<"FastestFinger"<<endl;
            }
        }
    }
    return 0;
}