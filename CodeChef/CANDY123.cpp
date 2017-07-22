#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		int i = 1;
		while(true){
			if(a >= i) a = a-i;
			else {
				cout<<"Bob"<<endl;break;
			}
			i++;
			if(b >= i) b = b-i;
			else{
				cout<<"Limak"<<endl;break;
			}
			i++;
		}
	}
}
