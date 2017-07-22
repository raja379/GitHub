#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		char matrix[n][m];
		for(int i=0; i<n; i++){
			string s;
			cin>>s;
			for(int j=0; j<m; j++){
				matrix[i][j] = s[j];
			}
		}
		bool ans = true;
		char left,right,up,down;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				switch(matrix[i][j]){
					case 'W':
						if(j-1 >= 0) left = matrix[i][j-1]; else {ans = false;}
						if(j+1 < m) right = matrix[i][j+1];  else {ans = false;}
						if(i-1 >= 0) up = matrix[i-1][j]; 
						if(i+1 < n) down = matrix[i+1][j]; else {ans = false; }
						if(j-1 >= 0)switch(left){
							case 'A': ans = false; break;
						}
						if(j+1 < m)switch(right){
							case 'A': ans = false; break;
						}
						if(i-1 >= 0)switch(up){
							case 'B': ans = false; break;
						}
						if(i+1 < n)switch(down){
							case 'A': ans = false; break;
						}
						break;
					case 'A':
						if(j-1 >= 0) left = matrix[i][j-1]; 
						if(j+1 < m) right = matrix[i][j+1];  //else {ans = false; break;}
						if(i-1 >= 0) up = matrix[i-1][j]; 
						if(i+1 < n) down = matrix[i+1][j]; //else {ans = false; break;}
						if(j-1 >= 0)switch(left){
							case 'W': ans = false; break;
						}
						if(j+1 < m) switch(right){
							case 'W': ans = false; break;
						}
						if(i-1 >= 0)switch(up){
							case 'W':
							case 'B': ans = false; break;
						}
						break;
					case 'B':
						if(j-1 >= 0) left = matrix[i][j-1];
						if(j+1 < m) right = matrix[i][j+1];
						if(i-1 >= 0) up = matrix[i-1][j]; 
						if(i+1 < n) down = matrix[i+1][j];
						if(i+1 < n)switch(down){
							case 'A':
							case 'W': ans = false; break;
						}
						break;
				}
			}
		}
		if(ans){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
}
