#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int x,y,k,n;
		cin>>x>>y>>k>>n;
		int p[n],c[n];
		for(int i=0; i<n; i++){
			cin>>p[i]>>c[i];
		}
		int d = x-y;
		bool possible[n];
		bool done = false;
		for(int i=0; i<n; i++){
			possible[i] = true;
			if(p[i] < d){
				possible[i] = false;
			}
			if(c[i] > k){
				possible[i] = false;
			}
			if(possible[i]){
				done = true;
			}
		}
		if(done){
			cout<<"LuckyChef"<<endl;
		}
		else{
			cout<<"UnluckyChef"<<endl;
		}
	}
}
