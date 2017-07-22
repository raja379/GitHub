    #include<iostream>
    #include<algorithm>
    #include<queue>
    #define INF 0x7fffffff
    using namespace std;
    int main(){
    	int t;
    	cin>>t;
    	while(t--){
    		int n,m,k1,k2;
    		cin>>n>>m>>k1>>k2;
    		int matrix[n][m];
    		int dist[n][m],dist2[n][m];
    		for(int i=0; i<n; i++){
    			for(int j=0; j<m; j++){
    				cin>>matrix[i][j];
    				dist[i][j] = INF;
    				dist2[i][j] = INF;
    			}
    		}
    		queue<int> qi;
    		queue<int> qj;
    		qi.push(0);
    		qj.push(0);
    		dist[0][0] = 0;
    		while(!qi.empty()){
    			int ai = qi.front();
    			qi.pop();
    			int aj = qj.front();
    			qj.pop();
    			for(int i=-k1; i <= k1 ; i++){
    				for(int j=-k1; j <= k1; j++){
    					if (ai+i >= 0 && ai+i < n && abs(i)+abs(j) <= k1 &&
    						aj+j >= 0 && aj+j < m && dist[ai+i][aj+j] == INF && !matrix[ai+i][aj+j] ){
    						dist[ai+i][aj+j] = dist[ai][aj] + 1;
    						qi.push(ai+i);
    						qj.push(aj+j);
    					}
    				}
    			}
    		}
    		
    		queue<int> pi;
    		queue<int> pj;
    		pi.push(0);
    		pj.push(m-1);
    		dist2[0][m-1] = 0;
    		while(!pi.empty()){
    			int ai = pi.front();
    			pi.pop();
    			int aj = pj.front();
    			pj.pop();
    			for(int i=-k2; i <= k2 ; i++){
    				for(int j=-k2; j <= k2; j++){
    					if (ai+i >= 0 && ai+i < n && abs(i)+abs(j) <= k2 &&
    						aj+j >= 0 && aj+j < m && dist2[ai+i][aj+j] == INF && !matrix[ai+i][aj+j] ){
    						dist2[ai+i][aj+j] = dist2[ai][aj] + 1;
    						pi.push(ai+i);
    						pj.push(aj+j);
    					}
    				}
    			}
    		}
    		
    		int dmin = INF;
    		for (int i = 0; i < n; i++)
    			for (int j = 0; j < m; j++)
    				if (max(dist[i][j], dist2[i][j]) < dmin)
    					dmin = max(dist[i][j], dist2[i][j]);
    		if(dmin == INF)
    			dmin = -1;
    		cout<<dmin<<endl;
    /*		int min = INF;
    		int ii = -1, jj = -1;
    		for(int i=0; i<n; i++){
    			for(int j=0; j<m; j++){
    				int temp = abs(dist[i][j] - dist2[i][j]);
    				if(min > temp && dist[i][j] != INF){
    					min = temp;
    					ii = i;
    					jj = j;
    				}
    			}
    		}
    	/*	for(int i=0; i<n; i++){
    			for(int j=0; j<m; j++){
    				if(dist[i][j] == INF)
    					cout<<"- ";
    				else
    					cout<<dist[i][j]<<" ";
    			}
    			cout<<endl;
    		}
    		for(int i=0; i<n; i++){
    			for(int j=0; j<m; j++){
    				if(dist2[i][j] == INF)
    					cout<<"- ";
    				else
    					cout<<dist2[i][j]<<" ";
    			}
    			cout<<endl;
    		}
    		if(dist[0][m-1] == INF){
    			cout<<-1<<endl;
    		}
    		else if(dist[ii][jj] > dist2[ii][jj]){
    			cout<<dist[ii][jj]<<endl;
    		}
    		else{
    			cout<<dist2[ii][jj]<<endl;
    		}*/
    	//	cout<<ii<<","<<jj<<endl;
     	}
    } 
