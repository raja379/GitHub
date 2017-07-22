#include<iostream>
#include<vector>
#include<list>
#include<queue>
#define i64 long long int
using namespace std;
struct Compare{
	bool operator()(pair<i64,i64> &a, pair<i64,i64> &b){
		return b.second > a.second;
	}
};
int main(){
	i64 t; cin>>t;
	while(t--){
		i64 n,d;
		cin>>n>>d;
		vector<list<pair<i64,i64> > > trainers(d+1);
		for(i64 i = 0; i < n; i++ ){
			pair<i64,i64> temp;
			i64 day;
			cin>>day>>temp.first>>temp.second;
			trainers[day].push_back(temp);
		}
		priority_queue<pair<i64,i64>, vector<pair<i64,i64> >, Compare > pq;
		for(i64 i = 1; i <= d; i++){
			for(list<pair<i64,i64> >::iterator ptr = trainers[i].begin(); ptr != trainers[i].end(); ptr++){
				pq.push(*ptr);
			}
			if(pq.empty()) continue;
			pair<i64,i64> temp = pq.top();
			pq.pop();
		//	cout<<temp.first<<" "<<temp.second<<endl;
			temp.first--;
			if(temp.first > 0) pq.push(temp);
		}
		i64 sum = 0;
		while(!pq.empty()){
			pair<i64,i64> temp = pq.top();
			sum += temp.second*temp.first;
			pq.pop();
		}
		cout<<sum<<endl;
	}
}
