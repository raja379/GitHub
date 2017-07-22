#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		bool isAll = false, isSome = false, isSad = false;
		bool x[100003];
		int count = k;
		for(int i = 0; i < k+1; i++){
			x[i] = false;
		}
		for(int i = 0; i < n; i++){
			int m;
			cin>>m;
			for(int j = 0; j < m; j++){
				int num;
				cin>>num;
				if(x[num]) continue;
				x[num] = true;
				count--;
			}
			if(i != n-1 && count == 0){
				isSome = true;
			}
		}
		if(count != 0){
			isSad = true;
		}
		if(isSad){
			cout<<"sad"<<endl;
		}
		else if(isSome){
			cout<<"some"<<endl;
		}
		else{
			cout<<"all"<<endl;
		}
	}
}
