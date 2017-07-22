#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool pos = false;
		int count = 0;
		for(int i=0; i<n; i++){
			int temp;
			cin>>temp;
			if(temp == 0){
				pos = true;
			}
			if(pos){
				if(temp)count+=100;
				else count+=1100;
			}
		}
		cout<<count<<endl;
	}
}
