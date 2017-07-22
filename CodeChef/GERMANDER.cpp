#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int o1,o2;
		cin>>o1>>o2;
		int n = o1*o2;
		int a[n];
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		int b[n];
		for(int i=0; i<n; i++){
			b[i] = 0;
		}
		for(int i = 0; i < o2; i++){
			b[0]+=a[i];
		}
		for(int i=1,j=o2; i < n; i++,j++){
			b[i] = b[i-1] + a[j%n] - a[i-1];
		}
		int c[o2];
		for(int i=0; i<o2; i++){
			c[i] = 0;
		}
		for(int i = 0; i < n; i++){
			c[i%o2] += (b[i] > o2/2);
		}
		int max = -1;
		for(int i = 0; i < o2; i++){
			if(max < c[i]){
				max = c[i];
			}
		}
		if(max > o1/2){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
	}
}
