#include<iostream>
#include<queue>
#include<list>
using namespace std;
struct thing
{
    int a;
    int label;
    bool operator>(const thing& rhs) const
    {
        return a > rhs.a;
    }
    bool operator<(const thing& rhs) const
    {
        return a < rhs.a;
    }
};
int main(){
	int t;
	cin>>t;
	while(t--){
		priority_queue<thing, std::vector<thing>, std::greater<thing> > q;
		int n;
		cin>>n;
		bool visited[n];
		char word[n+1];
		cin>>word;
		int arr[n];
		for(int i=0; i<n; i++){
			if(word[i] == '0')
				visited[i] = false;
			else
				visited[i] = true;
			int temp;
			cin>>temp;
			arr[i] = temp;
		}
		for(int i=0; i<n; i++){
			if(visited[i]){
				thing temp;
				if(i+1<n && !visited[i+1]){
					temp.label = i+1;
					temp.a = arr[i+1] - arr[i];
					q.push(temp);
				}
				if(i-1>=0 && !visited[i-1]){
					temp.label = i-1;
					temp.a = arr[i] - arr[i-1];
					q.push(temp);
				}
			}
		}
		int sum = 0;
		while(!q.empty()){
			thing temp = q.top();
			q.pop();
			if(!visited[temp.label])
				sum += temp.a;
			visited[temp.label] = true;
			int i = temp.label;
			if(i+1<n && !visited[i+1]){
				temp.label = i+1;
				temp.a = arr[i+1] - arr[i];
				q.push(temp);
			}
			if(i-1>=0 && !visited[i-1]){
				temp.label = i-1;
				temp.a = arr[i] - arr[i-1];
				q.push(temp);
			}
		}
		cout<<sum<<endl;
	}	
}
