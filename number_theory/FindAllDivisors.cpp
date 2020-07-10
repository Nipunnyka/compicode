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

void printDivisors(int n){
    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0){
            if(n/i==i){
                cout<<i<<" ";
            }
            else{
                cout<<i<<","<<n/i<<" ";
            }
        }
    }
    cout<<endl;
}

int main(){
    printDivisors(200);
    return 0;
}