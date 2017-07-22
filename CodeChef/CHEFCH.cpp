#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n = s.length();
		string c = "",d = "";
		for(int i = 0; i<n; i++){
			if(i%2 == 0){
				c = c+'+';
				d = d+'-';
			}else{
				c = c+'-';
				d = d+'+';
			}
		}
		int a = 0,b = 0;
		for(int i=0; i<n; i++){
			if(s[i]!=c[i]){
				a++;
			}
			if(s[i] != d[i]){
				b++;
			}
		}
		cout<<min(a,b)<<endl;
	}
}
