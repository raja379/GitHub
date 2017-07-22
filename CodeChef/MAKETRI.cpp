#include<iostream>
#include<algorithm>
#include<queue>
#include<list>
using namespace std;

bool myfunction (pair<long long int,long long int> a, pair<long long int,long long int> b) {
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;	
}
int main(){
	int n;
	long long int l,r;
	cin>>n>>l>>r;
	long long int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	sort(a,a+n);
	vector<pair<long long int,long long int> > v;
	for(int i=0; i+1 < n; i++){
		pair<long long int,long long int> temp;
		temp.first = a[i+1]-a[i]+1;
		temp.second = a[i+1]+a[i]-1;
		v.push_back(temp);
	}
	list<pair<long long int,long long int> > ans;
	sort(v.begin(),v.end(),myfunction);
	long long int count = 0;
	pair<long long int,long long int> temp = v[0];
	for(int i=1; i<v.size(); i++){
		if(temp.first <= v[i].first && v[i].first <= temp.second && temp.second <= v[i].second){ temp.second = v[i].second; }
		if(temp.first <= temp.second && temp.second < v[i].first && v[i].first <= v[i].second){
			ans.push_back(temp);
			temp = v[i];
		}
	}
	ans.push_back(temp);
	for(list<pair<long long int,long long int> >::iterator ptr = ans.begin(); ptr != ans.end(); ptr++){
		if(l <= ptr->first && ptr->first <= r && r <= ptr->second) count += r-ptr->first+1;
		else if(ptr->first <= l && l <= ptr->second && ptr->second <= r) count += ptr->second-l+1;
		else if(ptr->first <= l && l <= r && r <= ptr->second) count += r-l+1;
		else if(l <= ptr->first && ptr->first <= ptr->second && ptr->second <= r) count += ptr->second-ptr->first+1;
	}
	cout<<count<<endl;
}
