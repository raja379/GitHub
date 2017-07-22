#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++) cin>>a[i];
		sort(a,a+n);
		if(a[0]+1 != a[1]){
			cout<<a[0]<<endl;
			continue;
		}
		else if(a[n-1]-1 != a[n-2]){
			cout<<a[n-1]<<endl;
			continue;
		}
		else{
			for(int i = 0; i+1 < n; i++){
				if(a[i] == a[i+1]){
					cout<<a[i]<<endl;
					break;
				}
			}
			
		}
	}
}
