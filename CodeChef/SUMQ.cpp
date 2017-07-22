#include<iostream>
#include<algorithm>
#include<cstdio>
#define mod 1000000007
#define i64 unsigned long long int
#define mul(a,b) (((a)*(b))%mod)
using namespace std;
int main(){
	int t; scanf("%d",&t);
	while(t--){
		i64 p,q,r;
		scanf("%llu %llu %llu",&p,&q,&r);
		i64 a[p+1],b[q+1],c[r+1];
		a[0] = b[0] = c[0] = 0;
		for(i64 i = 1; i <= p; i++) scanf("%llu",&a[i]);
		for(i64 i = 1; i <= q; i++) scanf("%llu",&b[i]);
		for(i64 i = 1; i <= r; i++) scanf("%llu",&c[i]);
		sort(a+1,a+p+1);
		sort(b+1,b+q+1);
		sort(c+1,c+r+1);
		i64 ca[p+1],cc[r+1];
		ca[0] = cc[0] = 0;
		ca[1] = a[1];
		for(i64 i = 2; i <= p; i++) ca[i] = (ca[i-1] + a[i])%mod;
		cc[1] = c[1];
		for(i64 i = 2; i <= r; i++) cc[i] = (cc[i-1] + c[i])%mod;
		i64 sum = 0;
		i64 posa = 0, posc = 0;
		for(i64 i = 1; i <= q; i++){
			while(posa <= p && a[posa] <= b[i]) posa++; posa--;
			while(posc <= r && c[posc] <= b[i]) posc++; posc--;
			sum = (sum + mul(posc,mul(ca[posa],b[i])))%mod;
			sum = (sum + mul(ca[posa],cc[posc]))%mod;
			sum = (sum + mul(mul(posa,posc),mul(b[i],b[i])))%mod;
			sum = (sum + mul(posa,mul(b[i],cc[posc])))%mod;
		
		}
		printf("%llu\n",sum);
	}
} 
