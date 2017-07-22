#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	int ax,ay,bx,by,cx,cy;
	cin>>ax>>ay>>bx>>by>>cx>>cy;
	int a[n+1];
	a[1] = abs(ax*(by-cy) + bx*(cy-ay) + cx*(ay-by));
	int max = 1, min = 1;
	for(int i=2; i<=n; i++){
		cin>>ax>>ay>>bx>>by>>cx>>cy;
		a[i] = abs(ax*(by-cy) + bx*(cy-ay) + cx*(ay-by));
		if(a[max] <= a[i]){
			max = i;
		}
		if(a[min] >= a[i]){
			min = i;
		}
	}
	cout<<min<<" "<<max;
}
