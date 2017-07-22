#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int sum = 0, idx = 0;
		for(int i = 0; i < n; i++){
			int temp, id;
			cin>>id>>temp;
			idx += id;
			sum += temp;
		}
		cout<<idx-sum<<endl;
	}
	return 0;
}
