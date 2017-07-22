#include<iostream>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	bool a[n+1];
	for(int i=0; i<=n; i++)
		a[i] = false;
	int count = 0;
	for(int i=0; i<n; i++){
		string x;
		int temp;
		cin>>x;
		if(x == "CLICK"){
			cin>>temp;
			if(!a[temp]){
				count++;
				a[temp] = true;
			}
			else{
				count--;
				a[temp] = false;
			}
			cout<<count<<endl;
		}
		else{
			for(int i=0; i<=n; i++){
				a[i] = false;
			}
			count = 0;
			cout<<count<<endl;
		}
	}
}
