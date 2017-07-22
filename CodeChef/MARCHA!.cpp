    #include<iostream>
    using namespace std;
    int sum = 0;
    bool combinations(int a[] ,int s, int n, int price){
    	if(n-s == 0)
    		return false;
    	bool y = false;
    	for(int i=s; i<n; i++){
    		sum += a[i];
    		//cout<<"{"<<sum;
    		if(sum == price)
    			return true;
    		bool x = combinations(a,i+1,n,price);
    		sum -= a[i];
    		//cout<<sum<<"}"<<endl;
    		y = x|y;
    	}
    	return y;
    }
    int main(){
    	int t;
    	cin>>t;
    	while(t--){
    		::sum = 0;
    		int n, m;
    		cin>>n>>m;
    		int a[n];
    		for(int i=0; i<n; i++){
    			cin>>a[i];
    		}
    		bool x=combinations(a,0,n,m);
    		if(x)
    			cout<<"Yes"<<endl;
    		else
    			cout<<"No"<<endl;
    	}
    	return 0;
    } 
