#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int count[n][10];
	for(int j=0; j<10; j++){
		count[0][j] = 0;		
	}	
	for(int i=1; i<n; i++){
		for(int j=0; j<10; j++){
			count[i][j] = count[i-1][j];
			if(j == s[i-1]-'0'){
				count[i][j]++;
			}		
		}	
	}
	for(int i=0; i<m; i++){
		int x;
		cin>>x;
		int b1=0,b2=0;
		for(int j=0; j<10; j++){
			int temp = (s[x-1]-'0' - j)*count[x-1][j];
			if(temp >= 0){
				b1 += temp;
			}else{
				b2 += temp;
			}
		}
		cout<<b1-b2<<endl;
	}
}
