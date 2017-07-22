#include<iostream>
#include<list>
#include<stack>
#include<queue>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int cnt = n;
		if(n == 0 || n*(n-1) == 2*m){
			cout<<"YES"<<endl;
			continue;
		}
		list<int> graph[n+1];
		int count[n+1];
		for(int i=0; i<=n; i++){
			count[i]= 0;
		}
		for(int i=0; i<m; i++){
			int s,d;
			cin>>s>>d;
			count[s]++;
			count[d]++;
			graph[s].push_back(d);
			graph[d].push_back(s);
		}
		int count1 = 0, count2 = 0, edge1 = 0, edge2 = 0;
		int table[n+1];
		for(int i=0; i<=n; i++){
			table[i] = 0;
		}
		while(cnt){
			queue<int> q;
			for(int i=1; i<=n; i++){
				if(count[i] != cnt-1 && table[i] == 0){
	//				cout<<i<<" has been pushed initially count[i] = "<<count[i]<<endl;
					q.push(i);
					table[i] = 2;
					count2++;
					cnt--;
					break;
				}
			}
			if(q.empty()){
				break;
			}
			while(!q.empty()){
				int x = q.front();
	//			cout<<x<<" ";
				q.pop();
				bool visited[n+1];
				for(int i=0; i<=n; i++){
					visited[i] = false;
				}
				for(list<int>::iterator ptr = graph[x].begin(); ptr != graph[x].end(); ptr++){
					visited[*ptr] = true;
					count[*ptr]--;
				}
				for(int i=1; i<=n; i++){
					if(!visited[i] && table[i] == 0){
						if(table[x] == 1){
							table[i] = 2;
							count2++;
						}else{
							table[i] = 1;
							count1++;
						}
						q.push(i);
						cnt--;
					}
				}
			}
	//		cout<<endl;
		}
		for(int i=1; i<=n; i++){
			if(table[i] == 0){
				table[i] = 2;
				count2++;
			}
		}
	//	for(int i=1; i<=n; i++) cout<<table[i]<<" ";
	//	cout<<endl;
		for(int i=1; i<=n; i++){
			if(table[i] == 2){
				for(list<int>::iterator ptr = graph[i].begin(); ptr != graph[i].end(); ptr++){
					if(table[*ptr] == 2){
						edge2++;				
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			if(table[i] == 1){
				for(list<int>::iterator ptr = graph[i].begin(); ptr != graph[i].end(); ptr++){
					if(table[*ptr] == 1){
						edge1++;
					}
				}
			}
		}
		if(count1*(count1-1) == edge1 && count2*(count2-1)==edge2){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
