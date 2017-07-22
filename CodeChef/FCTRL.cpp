    #include<iostream>
    using namespace std;
    int main(){
    	int t;
    	cin>>t;
    	while(t--){
    		long long int n;
    		cin>>n;
    		int sum5 = 0;
    		for(int i = 5; i<=n; i = i*5){
    			sum5 += (int)n/i;
    		}
    		cout<<sum5<<endl;
    	}
    } 
