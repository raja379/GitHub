#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		map<int,int> mp;
		for(int i=0; i<n; i++){
			int m;
			cin>>m;
			int min = 0x7fffffff;
			for(int j=0; j<m; j++){
				int x,y;
				cin>>x>>y;
				if(min > x){
					min = x;
				}
			}
			a[i] = min;
			mp[min] = i;
		}
		sort(a,a+n);
		reverse(a,a+n);
		int ans[n];
		for(int i=0; i<n; i++){
			ans[mp[a[i]]] = i;
		}
		for(int i=0;i<n; i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
}
