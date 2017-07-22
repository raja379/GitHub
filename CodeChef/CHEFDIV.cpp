#include<iostream>
#include<list>
#include<vector>
#include<cmath>
#define i64 long long int
using namespace std;
i64 l,r;
vector<list<i64> > imp;
int primes[1000103];
list<i64> prime;
vector<list<i64> > distPrimes; 
void sieve(int n){
	prime.clear();
	for(int i = 0; i <= n; i++){
		primes[i] = -1;
	}
	for(int i = 2; i*i <= n; i++){
		if(primes[i] == -1) for(int j = i+i; j <= n; j += i){
			primes[j] = i;
		}
	}
	for(int i = 2; i < n; i++){
		if(primes[i] == -1) prime.push_back(i);
	}
}
void segmentedSieve(){
	distPrimes.resize(r-l+1);
	for(list<i64>::iterator ptr = prime.begin(); ptr != prime.end() && (*ptr)*(*ptr) <= r; ptr++){
		for(i64 j = l - l%(*ptr); j <= r; j += (*ptr)){
			if((*ptr)*(*ptr) <= j) if(j-l >= 0) distPrimes[j-l].push_back(*ptr);
		}
	}
}
void primesCount(){
	for(i64 i = l; i <= r; i++){
		i64 temp = i;
		for(list<i64>::iterator ptr = distPrimes[i-l].begin(); ptr != distPrimes[i-l].end(); ptr++){
			i64 j = *ptr;
			i64 count = 0;
			while(temp%j == 0 && temp != 1){
				temp = temp/j;
				count++;
			}
			if(count > 0) imp[i-l].push_back(count);
		}
		if(temp > 1) imp[i-l].push_back(1);
	}
}
list<i64>::iterator findMax(list<i64> &x){
	i64 max = 0;
	list<i64>::iterator ans;
	for(list<i64>::iterator ptr = x.begin(); ptr != x.end(); ptr++){
		if(max < *ptr){
			max = *ptr;
			ans = ptr;
		}
	}
	return ans;
}
i64 fun(list<i64> &x){
	if(x.size() == 0){
		return 0;
	}
	i64 ans = 1;
	for(list<i64>::iterator ptr = x.begin(); ptr != x.end(); ptr++){
		ans *= (*ptr+1);
	}
	list<i64>::iterator max = findMax(x);
	i64 temp = *max;
	if(temp != 1) x.push_back(temp-1);
	x.erase(max);
	return ans + fun(x);
}
int main(){
	cin>>l>>r;
	imp.resize(r-l+1);
	int n = sqrt(r);
	sieve(n+1);
	i64 score = 0;
	segmentedSieve();
	primesCount();
	for(i64 i = l; i <= r; i++){
		score += fun(imp[i-l]);
	}
	cout<<score<<endl;
}
