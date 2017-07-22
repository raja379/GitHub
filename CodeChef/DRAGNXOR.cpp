    #include<iostream>
    #define uint unsigned int
    using namespace std;
    int main(){
    	int t;
    	cin>>t;
    	while(t--){
    		uint n,a,b;
    		cin>>n>>a>>b;
    		uint counta = 0;
    		while(a){
    			if((a&1))
    				counta++;
    			a = a>>1;
    		}
    		//cout<<counta<<endl;
    		uint countb = 0;
    		while(b){
    			if((b&1))
    				countb++;
    			b = b>>1;
    		}
    		//cout<<countb<<endl;
    		//int q = (counta+countb)/(2*n);
    		uint r = (counta+countb)%(2*n);
    		if(r>n){
    			r = r-2*(r%n);
    		}
    		uint ans = 0;
    		for(int i=0; i<r; i++)
    			ans = (ans<<1) + 1;
    		ans = ans<<(n-r);
    		cout<<ans<<endl;
    	}
    } 
