#include<bits/stdc++.h>
using namespace std;
//int arr[1000000];
int tmp, t;
char brick[40][40];
string dp[40];

bool compare(string a, string b){
    //cout << "compare(" << a << "," << b << ")" << endl;
    return (a.compare(b) < 0);
}

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
            for(int row=r-1; row>=0; row--){
                char cu=brick[row][col];
                string cur(1, cu);
                //cout<<"check cur "<<cur;
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
					cout<<found<<" check "<<pos<<endl;
					//cout<<"s is here: "<<s<<endl;
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
			//sort(dp.begin(), dp.end());
			cout<<"Case #"<<tmp-t<<": "<<endl; 
			vector<string> myvector (dp, dp+ c);               
			vector<string>::iterator it;

			sort (myvector.begin(), myvector.end(), compare);

			//cout << "vector contains:";
			for (it=myvector.begin(); it!=myvector.end(); ++it)
				cout << " " << *it;
		
			cout << endl;
        }
	}
    
    return 0;
}

