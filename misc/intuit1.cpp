#include<bits/stdc++.h>

using namespace std;

int main(){
	unordered_map <int , char> map;
	
	for(int i=0; i<26; i++){
		map[i]=(char)(97+i);
	}
	
	char input[101];
	int n, len;
	//taking the input
	//since the end of the character stream isnt specified, the end will be whenever it encounters a number
	//here i will only consider a wrong input if n is not within its bounds since the instruction was ambiguous and written specifically for line 2 of input
	for(int i=0; i<100; i++){
		cin>>input[i];
		if(input[i]>122 || input[i]<97){
			len=i;
			n=input[i]-'0';
			if(n>=20 && n<=1){
				cout<<"-1";
				return 0;
			}
			input[i]=0;	
			break;
		}
	}
	//rotating the characters within bounds
	for(int i=0; i<len; i++){
		int tmp=(int)input[i];
		int inc=tmp+n+i; //increase by this amount
		if(inc>122){
			int t2=(tmp+n+i)-123; //map to valid index
			inc=t2%26;
			input[i]=map[inc];
		}
		else
			input[i]=map[inc-97];
		cout<<input[i];
	}
	//cout<<endl;
	return 0;
}
