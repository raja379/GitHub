#include<iostream>
#include<map>
#define i64 long long int
using namespace std;
i64 count(int a[],int s,int n){
	if(n-s == 2){
		if(a[s] > a[s+1]){
			swap(a[s],a[s+1]);
			return 1;
		}
		return 0;
	}
	int m = (s+n)>>1;
	int i = s;
	int j = m;
	int b[n];
	int k = s;
	i64 c = 0;
	while(i < m && j < n){
		if(a[i] < a[j]){
			b[k++] = a[i++];
		}
		else{
			c += m-i;
			b[k++] = a[j++];
		}
	}
	while(i < m){
		b[k++] = a[i++];
	}
	while(j < n){
		b[k++] = a[j++];
	}
	for(i = s; i < n; i++){
		a[i] = b[i];
	}
	return c;
}
i64 count_inversions(int a[],int s,int n){
	if(n-s == 1 || n-s == 0){
		return 0;
	}
	int m = (s+n)>>1;
	return count_inversions(a,s,m) + count_inversions(a,m,n) + count(a,s,n);
}
int main(){
	int n;
	cin>>n;
	map<int,int> m;
	for(int i = 0; i < n; i++){
		int a,b;
		cin>>a>>b;
		m[a] = b;
	}
	int arr[n];
	int i = 0;
	for(map<int,int>::iterator ptr = m.begin(); ptr != m.end(); ptr++){
		arr[i++] = ptr->second;
	}
	cout<<count_inversions(arr,0,n);
}
