    #include<iostream>
    using namespace std;
    int main(){
    	int t;
    	cin>>t;
    	while(t--){
    		int r;
    		cin>>r;
    		int x1, y1;
    		cin>>x1>>y1;
    		int x2, y2;
    		cin>>x2>>y2;
    		int x3, y3;
    		cin>>x3>>y3;
    		int dis1,dis2,dis3;
    		dis1 = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1); 
    		dis2 = (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2);
    		dis3 = (x3-x1)*(x3-x1) + (y3-y1)*(y3-y1);
    		int count = 0;
    		if(dis1 <= r*r)
    			count++;
    		if(dis2 <= r*r)
    			count++;
    		if(dis3 <= r*r)
    			count++;
    		if(count>=2)
    			cout<<"yes"<<endl;
    		else
    			cout<<"no"<<endl;
    	}
    } 
