#include<iostream>
#include<vector>
#include<algorithm>
#define i64 long long int
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		i64 n,k; cin>>n>>k;
		string s; cin>>s;
		vector<i64> v; i64 cur = 0;
		i64 a = 0,b = 0;
		i64 pre = 0;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == 'a') break;
			if(s[i] == 'b') pre++;
		}
		for(i64 i = 0; i < s.length(); i++){
			if(s[i] != 'a' && s[i] != 'b' ) continue;
			if(s[i] == 'a') v.push_back(cur),a++,cur = 0;
			if(s[i] == 'b') cur++,b++;
		}
		v.push_back(cur);
		i64 sum = 0;
		i64 mul = k*b-pre;// cout<<mul<<endl;
		for(int i = 1; i < v.size(); i++){
			sum += (k)*(2*mul+(k-1)*(-b))/2;
			mul -= v[i];
		//	cout<<v[i]<<" "<<sum<<endl;
		}
		cout<<sum<<endl;
	}
}
