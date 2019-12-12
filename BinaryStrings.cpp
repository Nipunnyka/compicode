//all the codes for performing binary ops on strings

#include <bits/stdc++.h>

using namespace std;

bool isGreater(string s){
    //tells if a strings is greater than zero
    for(int i=0; i<s.length(); i++){
        if(s[i]=='1') return true;
    }
    return false;
}

//only multiplies by powers of two
string multiply(string s, int mul){
    //only multiplies by powers of two
    int fac=log2(mul);
    s.resize(s.length()+fac, '0');
    return s;
}

string ands(string s1, string s2){
    int i=s1.length()-1;
    int j=s2.length()-1;
    string ans="";
    //bool flag=false; //tells if either of the string is at 0
    while(i>=0 || j>=0){
        if(i>=0 && j>=0){
            if(s1[i]=='1'&&s2[j]=='1')ans+='1';
            else ans+='0';
            i--; j--;
        }
        else {
            ans+='0';
            i--; j--;
        }
    }
    reverse(ans.begin(), ans.end());
    //cout<<ans<<endl;
    return ans;
}
string xors(string s1, string s2){
    int i=s1.length()-1;
    int j=s2.length()-1;
    if(i<0 || j<0){
        
    }
    bool flag=true;
    string ans="";
    if(i<0 || j<0){
        ans=(i<j?s2:s1);
        flag=false;
    }
    //cout<<"initial"<<" "<<ans<<endl;
    //bool flag=false; //tells if either of the string is at 0
    while((i>=0 || j>=0 )&& flag){
        if(i>=0 && j>=0){
            if(s1[i]!=s2[j])ans+='1';
            else ans+='0';
            i--; j--;
        }
        else if(i<0&&j>=0){
            if(s2[j]=='1') ans+='1';
            else ans+='0';
            j--;
        }
        else if(j<0&&i>=0){
            if(s1[i]=='1')ans+='1';
            else ans+='0';
            i--;
        }
    }
   
    if(flag)reverse(ans.begin(), ans.end());
   // cout<<ans<<endl;
    return ans;
}

int main()
{
   // cout<<"Hello World";
    string s =xors("10111", "");
    return 0;
}
