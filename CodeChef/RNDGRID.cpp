            #include<iostream>
            #include<vector>
            #include <bits/stdc++.h>
            #include<list>
            
            using namespace std;
             
            string ins;
            int l,n;
             
            bool verify(string m[],int i,int j){
            	if(j < 0 || j >= n) return false;
            	if(i < 0 || i >= n) return false;
            	if(m[i][j] == '#') return false;
            	return true;
            }
             
             
        int calc(string m[], int& i, int& j,int s, int e){
        	if(!verify(m,i,j)) return 0;
        	int count = 0;
        	for(int k = s; k < e; k++){
        		switch(ins[k]){
        			case 'R' : j = j+1; break;
        			case 'L' : j = j-1; break;
        			case 'U' : i = i-1; break;
        			case 'D' : i = i+1; break;
        		}
        		//cout<<count<<endl;
        		if(verify(m,i,j)) count++;
        		else return count;
        	}
        	return count;
        }
            
            int main(){
        		ios_base::sync_with_stdio(false);
            	cin.tie(NULL);
            	int t;
            	cin>>t;
            	while(t--){
            		cin>>l>>n; cin>>ins;
            		string mat[n];
            		for(int i = 0; i < n; i++){
            			cin>>mat[i];
            		}
            		int sqrtl = ceil(sqrt(l));
            		int inc = ceil((float)l/sqrtl);
            		int ans = 0;
            		int maxi[sqrtl], maxj[sqrtl], mini[sqrtl], minj[sqrtl], curi[sqrtl], curj[sqrtl], es[sqrtl][n][n];
            		for(int si = 0,ii = 0; si < l; si += inc, ii++){
    				//	if(ii > 0){curi[ii] = curi[ii-1]; curj[ii] = curj[ii-1]; maxi[ii] = curi[ii]; maxj[ii] = curj[ii]; mini[ii] = curi[ii]; minj[ii] = curj[ii];}
    					curi[ii] = curj[ii] = 0, maxi[ii] = 0, maxj[ii] = 0, mini[ii] = 0, minj[ii] = 0; 
        				for(int i = si; i < si+inc && i < l; i++){
        				//	cout<<ins[i];
        					switch(ins[i]){
        						case 'R' : curj[ii]++; break;
        						case 'L' : curj[ii]--; break;
        						case 'U' : curi[ii]--; break;
        						case 'D' : curi[ii]++; break;
        					}
        					if(mini[ii] > curi[ii]) mini[ii] = curi[ii];
        					if(minj[ii] > curj[ii]) minj[ii] = curj[ii];
        					if(maxi[ii] < curi[ii]) maxi[ii] = curi[ii];
        					if(maxj[ii] < curj[ii]) maxj[ii] = curj[ii];
        				}
        			//	cout<<" ";
        				int cs[n][n],ds[n][n],rs[n][n];
            			for(int i = 0; i < n; i++){
            				cs[0][i] = (mat[0][i] == '#');
        				}
        				for(int j = 0; j < n; j++){
        					for(int i = 1; i < n; i++){
        						cs[i][j] = cs[i-1][j] + (mat[i][j] == '#');
        					}
        				}
        				for(int i = 0; i < n; i++){
        					for(int j = 0; j < n; j++){
        						int x1 = mini[ii], x2 = maxi[ii];
        						if(i+x1 > 0 && i+x2 < n) ds[i][j] = cs[i+x2][j] - cs[i+x1-1][j];
        						else if(i+x1 <= 0 && i+x2 >= n) ds[i][j] = cs[n-1][j];
        						else if(i+x1 <= 0) ds[i][j] = cs[i+x2][j];
        						else ds[i][j] = cs[n-1][j] - cs[i+x1-1][j];
        					}
        				}
           				for(int i = 0; i < n; i++){
            				rs[i][0] = ds[i][0];
        				}	
        				for(int i = 0; i < n; i++){
        					for(int j = 1; j < n; j++){
        						rs[i][j] = rs[i][j-1] + ds[i][j];
        					}
        				}	
        				for(int i = 0; i < n; i++){
        					for(int j = 0; j < n; j++){
        						int y1 = minj[ii], y2 = maxj[ii];
        						if(j+y1 > 0 && j+y2 < n) es[ii][i][j] = rs[i][j+y2] - rs[i][j+y1-1];
        						else if(j+y1 <= 0 && j+y2 >= n) es[ii][i][j] = rs[i][n-1];
        						else if(j+y1 <= 0) es[ii][i][j] = rs[i][j+y2];
        						else es[ii][i][j] = rs[i][n-1] - rs[i][j+y1-1];
        					}
        				}
        			}/*
        			cout<<endl;
        			for(int k = 0; k < sqrtl; k++){
        				for(int i = 0; i < n ; i++){
        					for(int j = 0; j < n; j++){
        						cout<<es[k][i][j]<<" ";
    						}
    						cout<<endl;
    					}
    					cout<<endl;
    				}*/
        			for(int i = 0; i < n; i++){
            			for(int j = 0; j < n; j++){
            				int x = i, y = j, ii;
            				int sum = 0;
            				for(ii = 0; ii < sqrtl; ii++){
            					if((x+mini[ii]) >= 0 && (x+maxi[ii]) < n && (y+minj[ii]) >= 0 && (y+maxj[ii]) < n && es[ii][x][y] == 0 && ii != sqrtl-1) sum = sum+inc;
            					else{
            						int temp = calc(mat,x,y,ii*inc,min((ii+1)*inc,l));
            						if(temp == inc) sum = sum + temp;
            						else {
            							sum += temp;
            							ii = sqrtl;
            							break;
    								}
            						continue;
    							}
            					x = x+curi[ii]; y = y+curj[ii];
            					if( x < 0 || x >= n) break;
            					if( y < 0 || y >= n) break;
    						}
    						sum = sum + calc(mat,x,y,ii*inc,l);
    						ans = ans^sum;
           				}
           			}
            		cout<<ans<<endl;
            	}
            }   
