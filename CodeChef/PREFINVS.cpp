#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int count = 0;
	for(int i = 0; i+1 < s.length(); i++){
		if(s[i] != s[i+1]){
			count++;
		}
	}
	int n = s.length();
	if(s[0] == '0' && s[n-1] == '1'){
		cout<<count+1;
	}
	else if(s[0] == '0' && s[n-1] == '0'){
		cout<<count-1;
	}
	else if(s[0] == '1' && s[n-1] == '0'){
		cout<<count;
	}
	else{
		cout<<count+1;
	}
}
