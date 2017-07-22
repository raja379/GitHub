    #include<iostream>
    #include<string>
    using namespace std;
    int main(){
    	int t;
    	cin>>t;
    	while(t--){
    		string x;
    		cin>>x;
    		int one = 0, zero = 0;
    		int l = x.length();
    		for(int i=0; i<l; i++){
    			if(x[i] == '0'){
    				zero++;
    			}
    			else{
    				one++;
    			}
    		}
    		if(one == 1 || zero == 1){
    			cout<<"Yes"<<endl;
    		}
    		else{
    			cout<<"No"<<endl;
    		}
    	}
    	return 0;
    } 
