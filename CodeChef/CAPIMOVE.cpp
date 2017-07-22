#include<iostream>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int p[n];
		map<int,int> m;
		set<int> tree[n+1];
		for(int i=0; i<n; i++){
			cin>>p[i];
			m[p[i]] = i+1;
		}
		for(int i=1; i<=n; i++){
			tree[i].insert(i);
		}
		for(int i=0; i<n-1; i++){
			int s,d;
			cin>>s>>d;
			tree[s].insert(d);
			tree[d].insert(s);
		}
		sort(p,p+n);
		reverse(p,p+n);
		for(int i=1; i<=n; i++){
			int ans = 0;
			for(int j=0; j<n; j++){
				if(tree[i].find(m[p[j]]) != tree[i].end()){
					continue;
				}
				else{
					ans = m[p[j]];
					break;
				}
			}
			cout<<ans<<" ";
		}
		cout<<endl;
	}
}
