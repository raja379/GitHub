#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int t; scanf("%d ",&t);
	while(t--){
		string s;
		getline(cin,s);
		cout<<(char)toupper(s[0]);
		int pos = 0;
		for(int i = 1; i < s.length(); i++){
		//	cout<<s[i]<<endl;
			if(s[i] == ' '){
				pos = i+1;
				cout<<". "<<(char)toupper(s[i+1]);
			}
		}
		for(int i = pos+1; i < s.length(); i++){
			cout<<(char)tolower(s[i]);
		}
		cout<<endl;
	}
}
