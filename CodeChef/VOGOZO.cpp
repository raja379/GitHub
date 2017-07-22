#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i = 0; i < n; i++) cin>>a[i];
	sort(a,a+n);
	int cur = a[0];
	int count = 1;
	for(int i = 1; i < n; i++){
		if(a[i]-cur >= k){
			cur = a[i];
			count++;
		}
	}
	cout<<count;
}
