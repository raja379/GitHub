    #include<iostream>
    using namespace std;
    int main(){
    	int t;
    	cin>>t;
    	while(t--){
    		int n;
    		cin>>n;
    		int sum = 0,temp;
    		bool pass = true;
    		bool high = false;
    		for(int i=0; i<n; i++){
    			cin>>temp;
    			sum+=temp;
    			if(temp <= 2.0)
    				pass = false;
    			if(temp == 5)
    				high = true;
    		}
    		if((float)sum/n < 4.0)
    			pass = false;
    		if(pass && high)
    			cout<<"Yes"<<endl;
    		else
    			cout<<"No"<<endl;
    	}
    } 
