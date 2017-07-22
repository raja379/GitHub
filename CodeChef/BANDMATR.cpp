#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int sum = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				int temp;
				cin>>temp;
				if(temp) sum++;
			}
		}
		int dp[n];
		dp[0] = n;
		for(int i = 1; i < n; i++){
			int m = n-i;
			dp[i] = dp[i-1] + 2*m;
		}
		int i;
		for(i = 0; i < n; i++){
			if(sum <= dp[i]) break;
		}
		cout<<i<<endl;
	}
}
