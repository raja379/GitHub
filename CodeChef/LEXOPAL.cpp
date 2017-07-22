    #include<iostream>
    #include<string>
    #include<algorithm>
    #include<vector>
    using namespace std;
    int main(){
    	int t;
    	cin>>t;
    	while(t--){
    		string x;
    		cin>>x;
    		bool flag = true;
    		int l = x.length();
    		string y(x);
    		reverse(y.begin(),y.end());
    		vector<char> v;
    		for(int i = 0; i<l; i++){
    			if(x[i] == '.' && y[i] == '.'){
    				v.push_back('a');
    			}
    			else if(x[i] == '.'){
    				v.push_back(y[i]);
    			}
    			else if(y[i] == '.'){
    				v.push_back(x[i]);
    			}
    			else if(x[i] == y[i]){
    				v.push_back(x[i]);
    			}
    			else{
    			   flag = false; 
    			}
    		}
    		if(!flag)
    		    cout<<-1<<endl;
    		else
    		    for(vector<char>::iterator ptr = v.begin(); ptr != v.end(); ptr++){
    			    cout<<*ptr;
    		    }
    		cout<<endl;
    	}
    	return 0;
    } 
