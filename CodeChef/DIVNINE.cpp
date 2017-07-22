#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string x;
		cin>>x;
		int n = x.length();
		int sum = 0;
		for(int i=0; i<n; i++){
			sum += x[i]-'0';
		}
		if(sum >= 9 || n == 1){
			cout<<min(sum%9,(9-sum%9))<<endl;
		}
		else{
			cout<<(9-sum%9)<<endl;
		}
	}
}
