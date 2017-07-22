#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int r,c;
		cin>>r>>c;
		string s;
		cin>>s;
		bool flag = true;
		int i = 0,j = 0;
		int minx = 0,maxx = 0,miny = 0,maxy = 0;
		for(int k = 0; k < s.length(); k++){
			if(s[k] == 'L'){
				j = j-1;
			}
			else if(s[k] == 'R'){
				j = j+1;
			}
			else if(s[k] == 'U'){
				i = i-1;
			}
			else{
				i = i+1;
			}
			if(i < minx){
				minx = i;
			}
			if(i > maxx){
				maxx = i;
			}
			if(j < miny){
				miny = j;
			}
			if(j > maxy){
				maxy = j;
			}
		}
		if(maxx-minx >= r) flag = false;
		if(maxy-miny >= c) flag = false;
		if(flag) cout<<"safe"<<endl;
		else cout<<"unsafe"<<endl;
	}
}
