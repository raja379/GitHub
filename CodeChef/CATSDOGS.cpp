#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int c,d,l;
		cin>>c>>d>>l;
		bool ans = false;
		if(l%4 == 0){
			int q = l/4;
			if(c+d >= q && q >=max(c-d,d)){
				ans = true;
			}
		}
		if(ans){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
	}
}
