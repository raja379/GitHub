#include<iostream>

#define i64 unsigned long long int

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		i64 count = 0, mul = 1,ans = 0;
		for(int i = 0; i < s.length(); ){
			ans += mul*count;
			mul = 1;
			while(s[i++] == '1') count++; //cout<<count<<endl;
			i--;
			while(s[i++] == '0') mul++; //cout<<mul<<endl;
			i--;
		}
		if(s[s.length()-1] == '0'){
			ans += mul*count;
		}
		cout<<ans<<endl;
	}
}
