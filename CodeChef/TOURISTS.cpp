#include<iostream>
#include<set>
#include<list>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
int main(){
	vector<set<int> >graph;
	list<int> l;
	int n,e;
	set<pair<int,int> > uni,bi;
	cin>>n>>e;
	graph.resize(n+1);
	pair<int,int> edges[e];
	int degree[n+1];
	for(int i=0; i<=n; i++){
		degree[i] = 0;
	}
	for(int i=0; i<e; i++){
		int s,d;
		cin>>s>>d;
		edges[i].first = s;
		edges[i].second = d;
		degree[s]++;
		degree[d]++; 
	}
	for(int i=0; i<e; i++){
		pair<int,int> temp;
		temp.first = edges[i].second;
		temp.second = edges[i].first;
		if(uni.find(temp) == uni.end()){
			uni.insert(edges[i]);
		}
		else{
			uni.erase(temp);
			bi.insert(temp);
			uni.erase(edges[i]);
			bi.insert(edges[i]);
		}
	}
	for(set<pair<int,int> >::iterator ptr = uni.begin(); ptr != uni.end(); ptr++){
	//	cout<<ptr->first<<" "<<ptr->second<<endl;
		graph[ptr->first].insert(ptr->second);
		graph[ptr->second].insert(ptr->first);
	}
	//cout<<endl;
	for(set<pair<int,int> >::iterator ptr = bi.begin(); ptr != bi.end(); ptr++){
	//	cout<<ptr->first<<" "<<ptr->second<<endl;
		graph[ptr->first].insert(ptr->second);
	}
	/*for(int i=1; i<=n; i++){
		for(set<int>::iterator ptr = graph[i].begin(); ptr != graph[i].end(); ptr++){
			cout<<*ptr<<" ";
		}
		cout<<endl;
	}*/
	bool ans = true;
	queue<int> qu;
	qu.push(1);
	bool visited[n+1];
	
	for(int i=0; i<=n; i++) visited[i] = false;
	visited[1] = true;
	int count = n-1;
	while(!qu.empty()){
		int x = qu.front();
		qu.pop();
		for(set<int>::iterator ptr = graph[x].begin(); ptr != graph[x].end(); ptr++){
			if(!visited[*ptr]){
				visited[*ptr] = true;
				count--;
				qu.push(*ptr);
			}
		}
	}
	for(int i=0; i<=n; i++){
		if(degree[i]%2 != 0 ){
			ans = false;
		}
	}
	if(count != 0){
		ans = false;
	}
	if(!ans){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	set<pair<int,int> > lp;
	for(int i=1; i<=n; i++){
		int temp = i;
		if(!graph[temp].empty()){
			do{
				pair<int,int> p;
				p.first = temp;
				p.second = *graph[temp].begin();
				if(bi.find(p) == bi.end()){
					pair<int,int> q;
					q.first = temp;
					q.second = *graph[temp].begin();
					lp.insert(q);
				//	cout<<temp<<" "<<*graph[temp].begin()<<endl;
					int k = *graph[temp].begin();
					graph[temp].erase(k);
					graph[k].erase(temp);
					temp = k;
				}
				else{
					pair<int,int> q;
					q.first = temp;
					q.second = *graph[temp].begin();
					lp.insert(q);
					int k = *graph[temp].begin();
					graph[temp].erase(k);
					temp = k;
				}
			}while(temp != i);
		}
	}
	for(int i=0; i < e; i++){
		if(lp.find(edges[i]) != lp.end()){
			cout<<edges[i].first<<" "<<edges[i].second<<endl;
		}
		else{
			cout<<edges[i].second<<" "<<edges[i].first<<endl;
		}
	}
}
