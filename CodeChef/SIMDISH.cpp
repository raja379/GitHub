#include<iostream>
#include<map>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string x[4],y[4];
		for(int i = 0; i < 4; i++) cin>>x[i];
		for(int i = 0; i < 4; i++) cin>>y[i];
		int count = 0;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(x[i] == y[j]){
					count++;
				}
			}
		}
		if(count >= 2){
			cout<<"similar"<<endl;
		}
		else{
			cout<<"dissimilar"<<endl;
		}
	}
}
