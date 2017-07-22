#include<iostream>
#include<map>
#include<algorithm>
#include<cstdio>
using namespace std;
map<unsigned long long int,unsigned long long int> m;
long long int fun(long long int n){
	map<unsigned long long int,unsigned long long int>::iterator ptr = m.find(n);
	if(ptr != m.end())
		return m[n];
	m[n] = max(n,fun(n/2)+fun(n/3)+fun(n/4));
	return m[n];
}
int main(){
	unsigned long long int n;
	m[0] = 0;
	while(scanf("%llu",&n)!=EOF){
		cout<<fun(n)<<endl;
	}
}
