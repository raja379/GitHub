#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s,t;
		cin>>s>>t;
		int cnts[26],cntt[26];
		for(int i=0; i<26; i++){
			cnts[i] = cntt[i] = 0;
		}
		int m = s.length(), n = t.length();
		for(int i=0; i<m; i++){
			cnts[s[i] - 97]++;
		}
		for(int i=0; i<n; i++){
			cntt[t[i] - 97]++;
		}
		bool guess = true;
		bool equal = true;
		for(int i=0; i<26; i++){
			if((cnts[i] && !cntt[i]) || (!cnts[i] && cntt[i])){
				guess = false;
			}
			if(cnts[i] != cntt[i]){
				equal = false;
			}
		}
		if(equal == guess){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}
