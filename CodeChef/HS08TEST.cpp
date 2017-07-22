#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int a;
	float b;
	cin>>a>>b;
	float ans = b - a - 0.5;
	if(ans < 0 || a%5 != 0)
		ans = b;
	cout<<fixed<<setprecision(2)<<ans;
}
