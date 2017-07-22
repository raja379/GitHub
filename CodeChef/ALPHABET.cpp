#include<iostream>
#include<string>
using namespace std;
int main(){
	string x;
	cin>>x;
	bool alpha[26];
	for(int i=0; i<26;i++){
		alpha[i] = false;
	}
	int l = x.size();
	for(int i=0; i<l; i++){
		alpha[x[i]-97] = true;
	}
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		string wrd;
		bool flag = true;
		cin>>wrd;
		int m = wrd.size();
		for(int j=0; j<m; j++){
			if(!alpha[wrd[j]-97])
				flag = false;
		}
		if(!flag){
			cout<<"No"<<endl;
		}
		else{
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}
