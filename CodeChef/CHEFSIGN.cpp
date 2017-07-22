#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		string s;
		cin>>s;
		int count = 1, max = 1;
		bool flag = false;
		char prev = s[0];
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '=') continue; flag = true;
			if(i == 0) continue;
			if(prev == s[i]) count++;
			else count = 1;
			prev = s[i];
			if(max < count) max = count;
		}
		if(flag) cout<<max+1<<endl;
		else cout<<1<<endl;
	}
}
