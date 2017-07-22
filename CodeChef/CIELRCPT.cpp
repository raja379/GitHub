#include<iostream>
using namespace std;
int binsum(int x){
	int count = 0 ;
	while(x){
		if((x&1)){
			count++;
		}
		x = (x>>1);
	}
	return count;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		int count = 0;
		if(x <= 2048){
			count += binsum(x);
		}
		else{
			count += x/2048;
			x = x%2048;
			count += binsum(x);
		}
		cout<<count<<endl;
	}
}
