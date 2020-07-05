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
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int smallest=INT_MAX;
        int secSmall=INT_MAX;
        
        unordered_map<int, int> umap;
        unordered_map<int, int> umap2;

        //check if all elements are same
        for(auto it=arr.begin(); it!=arr.end(); it++){
            umap2[ptr]++;
        }
        if(umap2[arr[0]]==arr.size()){
            return true;
        }

        for(auto it=arr.begin(); it!=arr.end(); it++){
            
            if(ptr<smallest){
                secSmall=smallest;
                smallest=ptr;
            }
            if(smallest!=ptr){
                secSmall= (ptr<secSmall && ptr>smallest)? ptr: secSmall;
            }
            if(umap.find(ptr)!=umap.end()){
                cout<<"here2";
                return false;;
            }
            umap[ptr]=1;
        }
        
        
        int d=secSmall-smallest;
        
        for(int i=0; i<arr.size()-2; i++){
            if(umap.find(secSmall+d)==umap.end()){
                //cout<<"here for "<<secSmall+d<<endl;
                //cout<<i;
                return false;;
            }
            secSmall+=d;
        }
        
        return true;
    }
};

int main(){
    Solution *s=new Solution();
    vector<int> arr={-68,-96,-12,-40,16};
    bool ans=(*s).canMakeArithmeticProgression(arr);
    if(ans){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    
    return 0;
}