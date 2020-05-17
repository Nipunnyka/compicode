#include<bits/stdc++.h>
using namespace std;
//int arr[1000000];
int tmp, t;
string brick[40][40];
string dp[40]={""};
int main(){
    cin>>t;
    tmp=t;
    while(t--){
        int r, c;
        cin>>r>>c;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin>>brick[i][j];
            }
        }
        string ans="";
        bool flag=false;
        for(int col=0; col<c; col++){
            string s="";
            int pos=-1;
            for(int row=r-1; row>=0; row++){
                string cur=brick[row][col];
                size_t found=s.find(cur);
                if(pos==-1){
                    s=s+cur;
                    pos++;
                }
                else if(found==string::npos){
                    s=s+cur;
                    pos++;
                }
                else if(found<pos){
					flag=true;
				}   
            }
            if(flag)
            {
				ans="-1";
				break;
			}
			else{
				dp[col]=s;
			}
        }
        if(ans=="-1")
		{cout<<"Case #"<<tmp-t<<": "<<ans<<endl; }
		else{
			 cout<<"Case #"<<tmp-t<<": "<<endl; 
			 for(int i=0; i<c; i++)
				cout<<dp[i]<<" ";
			cout<<endl;
        }
	}
    
    
	
    return 0;
}

