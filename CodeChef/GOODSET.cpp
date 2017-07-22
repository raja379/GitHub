#include<iostream>
using namespace std;
int main(){
	int t; cin>>t;
	bool a[502];
	a[1] = a[2] = a[4] = a[7] = true;
	a[3] = a[5] = a[6] = a[8] = a[9] = false;
	for(int i = 10; i <= 500; i++){
		a[i] = a[i-3];
	}
	while(t--){
		int n; cin>>n;
		int i = 1;
		while(n){
			if(a[i]){
				cout<<i<<" ";
				n--;
			}
			i++;
		}
		cout<<endl;
	}
}
