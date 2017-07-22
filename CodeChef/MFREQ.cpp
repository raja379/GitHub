#include<iostream>
#include<vector>
using namespace std;
int intersect(int a, int b, int l,int r){
	if(a <= l &&  r <= b) return r-l+1;
	if(l <= a &&  b <= r) return b-a+1;
	if(a <= l &&  b <= r) return b-l+1;
	if(l <= a &&  r <= b) return r-a+1;
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin>>a[i];
	vector<pair<int,int> > ranges;
	int temp = a[0];
	pair<int,int> p;
	p.first = 0;
	for(int i = 1; i < n; i++){
		if(a[i] != temp){
			p.second = i-1;
			ranges.push_back(p);
			p.first = i;
			temp = a[i];			
		}
	}
	p.second = n-1;
	ranges.push_back(p);
	vector<int> begin(n),end(n);
	for(int i = 0, j =0; i < n && j < ranges.size(); i++){
		begin[i] = ranges[j].first;
		end[i] = ranges[j].second;
		if(i == ranges[j].second){
			j++;
		}
	}
	for(int i = 0; i < m; i++){
		int l,r,k;
		cin>>l>>r>>k;
		l--; r--;
		int x = (l+r)/2;
		int res1 = intersect(begin[x],end[x],l,r), ans = -1;
		if(res1 >= k){
			ans = a[x];	
		}
		cout<<ans<<endl;
	}
}
