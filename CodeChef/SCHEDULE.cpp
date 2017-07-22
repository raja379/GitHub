#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int findAnswer(string s, int k){
	if(k == 0) return 0x7fffffff;
	if(k == 1){
		int a = 0,sum = 0;
		int n = s.length();
		for(int i = 0; i < s.length(); i++){
			sum += (a^(s[i]-'0'));
			if(a == 0) a = 1;
			else a = 0;
		}
		return min(sum,n-sum);
	}
	int res2 = 0;
	int res1 = 1;
    int temp = s[0];//it represents the last elemnet
    int i=1;
    while(i < s.length()){
      if(s[i] == temp){
	  	res1++;//the no of consecutive elements
		if(res1>k){
			if(s[i]==s[i+1]){
				if(s[i]) s[i] = 0;
				else s[i] = 1;
			}//it flips the ith element
       	   else{
				if(s[i]) s[i] = 0;
				else s[i] = 1;
			}
    		   
       		res2++;//it counts the no of changes
            res1=1;
        }            
      }
      else
         res1=1;

	  temp=s[i];
      i++;
    }
    return res2;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		int max = -1,val = -1;
		int l = 0, u = n, mid = (l+u)/2;
		while(l <= u){
			int x = findAnswer(s,mid);
			//cout<<mid<<" "<<x<<endl;
			if(x > k) l = mid+1;
			else if(x <= k){
				if(max <= x){
					max = x;
					val = mid;
				} 
				 u = mid-1;
			}
			mid = (l+u)/2;
		}
		cout<<val<<endl;
	}
}
