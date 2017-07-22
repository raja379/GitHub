#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n],b[n];
		for(int i = 0; i < n; i++) cin>>a[i];
		for(int i = 0; i < n; i++) cin>>b[i];
		int s1 = 0, s2 = 0;
		for(int i = 0; i < n; i++){
			if(i&1){
				s1 += a[i];
				s2 += b[i];
			}
			else{
				s1 += b[i];
				s2 += a[i];
			}
		}
		if(s1 < s2) cout<<s1<<endl;
		else cout<<s2<<endl;
	}
}
