#include<iostream>
#include<list>
#include<queue>

#define i64 long long int
#define INFINITY 0x7fffffffffffffff

using namespace std;

class Compare{
	public:
	bool operator()(pair<i64,i64> &a, pair<i64,i64> &b) const{
		return a.second > b.second;
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		i64 n,k,x,m,s;
		cin>>n>>k>>x>>m>>s;
		list<pair<i64,i64> > adj[n+1];
		for(int i = 0; i < k; i++){
			pair<i64,i64> temp; temp.first = -1; temp.second = x;
			adj[i].push_back(temp);
		}
		for(int i = 0; i < m; i++){
			i64 u,v,w;
			cin>>u>>v>>w;
			pair<i64,i64> temp; temp.first = v; temp.second = w;
			adj[u].push_back(temp);
			temp.first = u;
			adj[v].push_back(temp);
		}
		i64 dist[n+1];
		bool visited[n+1];
		for(int i = 0; i <= n; i++) dist[i] = INFINITY;
		for(int i = 0; i <= n; i++) visited[i] = false;
		pair<i64,i64> init;
		init.first = s, init.second = 0;
		priority_queue<pair<i64,i64>, vector<pair<i64,i64> >, Compare> pq;
		pq.push(init);
		bool cliqueVisit = false;
		while(!pq.empty()){
			pair<i64,i64> peek = pq.top();
			pq.pop();
		//	cout<<peek.first<<" "<<peek.second<<endl;
			if(peek.first == -1){
				if(cliqueVisit) continue;
				cliqueVisit = true;
				for(int i = 1; i <= k; i++){
					if(visited[i]) continue;
					visited[i] = true;
					dist[i] = peek.second;
					for(list<pair<i64,i64> >::iterator ptr = adj[i].begin(); ptr != adj[i].end(); ptr++){
						if(visited[ptr->first]) continue;
						pair<i64,i64> temp;
						temp.first = ptr->first;
						temp.second = ptr->second + peek.second;
						pq.push(temp);
					}
				}
				continue;
			}
			if(visited[peek.first]) continue;
		//	cout<<peek.first<<" "<<peek.second<<"<---"<<endl;
			visited[peek.first] = true;
			dist[peek.first] = peek.second;
			for(list<pair<i64,i64> >::iterator ptr = adj[peek.first].begin(); ptr != adj[peek.first].end(); ptr++){
				if(ptr->first == -1) if(cliqueVisit) continue;
				else if(visited[ptr->first]) continue;
				pair<i64,i64> temp;
				temp.first = ptr->first;
				temp.second = ptr->second + peek.second;
				pq.push(temp);
			}
		}
		for(int i = 1; i <= n; i++) cout<<dist[i]<<" "; cout<<endl;
	}
}
