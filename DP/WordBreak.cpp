//popular work break problem
//WARNING: DOESNT PASS SOME CASES, NEED TO DEBUG
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
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>



//#if defined(_USE_MATH_DEFINES) && !defined(_MATH_DEFINES_DEFINED)
//#define _MATH_DEFINES_DEFINED
//
///* Define _USE_MATH_DEFINES before including math.h to expose these macro
// * definitions for common math constants.  These are placed under an #ifdef
// * since these commonly-defined names are not part of the C/C++ standards.
// */
//
///* Definitions of useful mathematical constants
// * M_E        - e
// * M_LOG2E    - log2(e)
// * M_LOG10E   - log10(e)
// * M_LN2      - ln(2)
// * M_LN10     - ln(10)
// * M_PI       - pi
// * M_PI_2     - pi/2
// * M_PI_4     - pi/4
// * M_1_PI     - 1/pi
// * M_2_PI     - 2/pi
// * M_2_SQRTPI - 2/sqrt(pi)
// * M_SQRT2    - sqrt(2)
// * M_SQRT1_2  - 1/sqrt(2)
// */
//
//#define M_E        2.71828182845904523536
//#define M_LOG2E    1.44269504088896340736
//#define M_LOG10E   0.434294481903251827651
//#define M_LN2      0.693147180559945309417
//#define M_LN10     2.30258509299404568402
//#define M_PI       3.14159265358979323846
//#define M_PI_2     1.57079632679489661923
//#define M_PI_4     0.785398163397448309616
//#define M_1_PI     0.318309886183790671538
//#define M_2_PI     0.636619772367581343076
//#define M_2_SQRTPI 1.12837916709551257390
//#define M_SQRT2    1.41421356237309504880
//#define M_SQRT1_2  0.707106781186547524401
//
//#endif  /* _USE_MATH_DEFINES */
//


using namespace std::chrono; 
using namespace std;

string space=" ";

string getString(char x){
    return string(1,x);
}

int dp[1000][1000]={0};

bool dictContains(string s, vector<string> dict){
    for(auto &e: dict){
        if(e==s){
            return true;
        }
    }
    return false;
}

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_map<int, vector<string>> wordsUntilIndex;

        //fill diagonal
        bool flag=false;
        for(int i=0; i<n; i++){
            for(auto &e: wordDict){
                if(getString(s[i])==e){
                    flag=true;
                    dp[i][i]=1;
                    wordsUntilIndex[i].pb(getString(s[i]));
                }
            }
            if(flag==false){
                dp[i][i]=0;
            }
        }

        //fill for 2 letter words
        for(int i=0; i<n-1; i++){
            if(dictContains(s.substr(i,i+2), wordDict)){
                wordsUntilIndex[i+1].pb(s.substr(i,i+2));
                dp[i][i+1]=1;
            }
            if(dp[i][i]&&dp[i+1][i+1]){
                wordsUntilIndex[i+1].pb(getString(s[i])+space+getString(s[i+1]));
            }
        }
        vector<string> ans;
        for(int l=3;l<=n; l++){
            for(int i=0; i<n-l+1; i++){
                //if cur window is a valiv word
                if(dictContains(s.substr(i, i+l), wordDict)){
                    dp[i][i+l-1]=1;
                    if(i>0){
                        if(wordsUntilIndex[i-1].size()>0){
                            for(auto &e: wordsUntilIndex[i-1]){
                                string ns=e+space+s.substr(i, i+l);
                                wordsUntilIndex[i+l-1].pb(ns);
                            }
                        }
                        else{
                            ans.clear();
                            return ans;
                        }
                    }
                    wordsUntilIndex[i+l-1].pb(s.substr(i, i+l));
                }

                for(int k=0; k<l-1; k++){
                    int colChange=i+k;
                    int rowChange=i+k+1;
                    //if window can be split into set of valid words
                    if(dp[i][colChange]&&dp[rowChange][i+l-1]){
                        if(i>0){
                            if(wordsUntilIndex[i-1].size()>0){
                                for(auto &e: wordsUntilIndex[i-1]){
                                    string ns=e+space+s.substr(i, i+k+1)+space+s.substr(i+k+1, i+l);
                                    wordsUntilIndex[i+l-1].pb(ns);
                                }
                            }
                            else{
                                ans.clear();
                                return ans;
                            }
                        }
                        else{
                            dp[i][i+l-1]=1;
                            wordsUntilIndex[i+l-1].pb(s.substr(i, i+k+1)+space+s.substr(i+k+1, i+l));
                        }
                    }
                }

            }
        }

        for(auto &e: wordsUntilIndex[n-1]){
            ans.pb(e);
        }
        return ans;
        
    }
};

int main(){

    string str="leetcode";
    vector<string> dict={"code", "leet"};
    Solution s;
    vector<string> ans=s.wordBreak(str, dict);
    //cout<<dictContains("lee", dict);
    for(auto &e: ans){
        cout<<e<<" ";
    }
    cout<<endl;
    return 0;
}
