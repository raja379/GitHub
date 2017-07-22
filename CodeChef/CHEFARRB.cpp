#include<iostream>
using namespace std;
bool check(int cnt[],int k){
	unsigned int temp = 0;
	for(int i=0; i<32; i++){
//		cout<<cnt[i]<<" ";
		temp += (cnt[i] > 0)*(1<<i);
	}
//	cout<<temp<<endl;
	return (temp>=k);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		unsigned int a[n];
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		int cnt[32];
		for(int i=0; i<32; i++){
			cnt[i] = 0;
		}
		int j=0;
		unsigned int ans = 0;
		for(int i=0; i<n; i++){
			while(!check(cnt,k) && j<n){
				for(int l=0; l<32; l++){
					cnt[l] += (a[j]&(1<<l));
				}
				j++;
			}
			//cout<<check(cnt,k)<<" "<<j<<endl;
			if(check(cnt,k))
				ans += n-j+1;
			for(int l=0; l<32; l++){
				cnt[l] -= (a[i]&(1<<l));
			}
		}
		cout<<ans<<endl;
	}
}
