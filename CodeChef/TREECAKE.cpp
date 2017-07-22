#include<iostream>

#define i64 unsigned long long int
#define MOD 1000000007

using namespace std;

i64** T = 0; 
i64** S = 0; 
i64** U = 0;
i64 F[] = {1,1,1};
	
i64** multiply(i64** A,i64** B){
	i64** C = 0;
	C = new i64*[3];
	C[0] = new i64[3];
	C[1] = new i64[3];
	C[2] = new i64[3];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			C[i][j] = 0;
			for(int k = 0; k < 3; k++){
				C[i][j] = (C[i][j] + (A[i][k]*B[k][j])%MOD)%MOD; 
			}
		}
	}	
	return C;
}

i64** expPower(i64** A,i64 n){
	if(n == 1){
		return A;
	}
	if(n == 2){
		return multiply(A,A);
	}
	if(n&1){
		return multiply(expPower(A,n-1),A);
	}
	return expPower(multiply(A,A),n/2);
}

i64 mult(i64 F[3],i64** M){
	return ((M[0][0]*F[0])%MOD + (M[0][1]*F[1])%MOD - (M[0][2]*F[2])%MOD + MOD)%MOD;
}

i64 solve(i64 n){
	if(n == 0){
		return F[0];
	}
	i64 q = n/3;
	i64 r = n%3;
	i64** temp;
	if(q == 0){
		if(r == 1) temp = S;
		if(r == 2) temp = multiply(T,S);
	}
	else{
		if(q > 0) temp = expPower(U,q);
		if(r == 1) temp = multiply(S,temp);
		if(r == 2) temp = multiply(T,multiply(S,temp));
	}
	return mult(F,temp);
}

int main(){
	T = new i64*[3];
	T[0] = new i64[3];
	T[1] = new i64[3];
	T[2] = new i64[3];
	T[0][0] = 0, T[0][1] = 1, T[0][2] = 0;
	T[1][0] = 1, T[1][1] = 1, T[1][2] = 0;
	T[2][0] = 0, T[2][1] = 0, T[2][2] = 1;
	S = new i64*[3];
	S[0] = new i64[3];
	S[1] = new i64[3];
	S[2] = new i64[3];
	S[0][0] = 0, S[0][1] = 1, S[0][2] = 0;
	S[1][0] = 1, S[1][1] = 1, S[1][2] = 1;
	S[2][0] = 0, S[2][1] = 0, S[2][2] = 1;
//	T = {{0,1,0},{1,1,0},{0,0,1}};
//	S = {{0,1,0},{1,1,1},{0,0,1}};
	U = multiply(multiply(T,T),S);
	int t;
	cin>>t;
	while(t--){
		i64 n;
		cin>>n;
		cout<<solve(n-1)<<endl;
	}
}
