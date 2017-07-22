#include<iostream>
#define ull unsigned long long int
using namespace std;
int main(){
	ull n;
	cin>>n;
	ull count[64];
	for(int i=0; i<64; i++){
		count[i] = 0;
	}
	for(int i=0; i<n; i++){
		ull temp;
		cin>>temp;
		int j = 0;
		while (temp){
			count[j] += (temp&1);
			temp = (temp>>1);
			j++;
		}
	}
	ull val = 1;
	ull sum = 0;
	for(int i=0; i<64; i++){
		sum += val*count[i]*(count[i]-1)/2;
		val = (val<<1);
	}
	cout<<sum;
}
