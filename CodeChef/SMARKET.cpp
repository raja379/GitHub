
#include<bits/stdc++.h>

#define gc getchar_unlocked
#define pc putchar_unlocked

using namespace std;

char buffer[35];

struct query{
	int left,right,k,index;
};
// Fast I/O
/*inline void read(int &x){
    register char c = gc();
    for(;c<'0' || c>'9';c=gc());
    x=0;
    for(;c>='0' && c<='9';c=gc())
        x = (x<<3)+(x<<1)+(c-'0');
}

inline void write(int x){
    register int i = 0;
    do
        buffer[i++]=x%10+'0',x/=10;
    while (x);
    while(i-1>=0)
        pc(buffer[--i]);
    pc('\n');
}
*/
int m;

bool comp_mo(const query &a, const query &b){
	int ax = a.left/m;
    int bx = b.left/m;
    if (ax != bx)
        return ax < bx;
    return a.right < b.right;
}

int counter[100003];
deque<int> dq;
int l,r;
vector<int> a;

inline void addRight(){
	r++;
	if(a[r] == a[r-1]){
		int temp = dq.back();
		dq.pop_back();
		dq.push_back(temp+1);
		counter[temp+1]++;
	}
	else{
		dq.push_back(1);
		counter[1]++;
	}
}

inline void addLeft(){
	l--;
	if(a[l] == a[l+1]){
		int temp = dq.front();
		dq.pop_front();
		dq.push_front(temp+1);
		counter[temp+1]++;
	}
	else{
		dq.push_front(1);
		counter[1]++;
	}
}

inline void removeLeft(){
	l++;
	int temp = dq.front();
	counter[temp]--;
	dq.pop_front();
	if(temp > 1) dq.push_front(temp-1);
}

inline void removeRight(){
	r--;
	int temp = dq.back();
	counter[temp]--;
	dq.pop_back();
	if(temp > 1) dq.push_back(temp-1);
}

int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	//read(t);
	while(t--){
		dq.clear();
		l = 0, r= 0; 
		for(int i = 0; i < 100003; i++) counter[i] = 0;
		int n,q;
		cin>>n>>q;//read(n); read(q);
		m = ceil(sqrt(n));
		a.resize(n+1);
		for(int i = 1; i <= n; i++){
			cin>>a[i];//read(a[i]);
		}
		query qr[q];
		int sol[q];
		for(int i = 0; i < q; i++){
			//read(qr[i].left); read(qr[i].right); read(qr[i].k);//scanf("%d%d%d",&qr[i].left,&qr[i].right,&qr[i].k);//
			cin>>qr[i].left>>qr[i].right>>qr[i].k;
			qr[i].index = i;
		}
		sort(qr,qr+q,comp_mo); //sort queries
		l = qr[0].left, r = qr[0].left, dq.push_back(1), counter[1]++;
		for(int i = 0; i < q; i++){
			while(r < qr[i].right){
				addRight();
			}
			while(r > qr[i].right){
				removeRight();
			}
			while(l < qr[i].left){
				removeLeft();
			}
			while(l > qr[i].left){
				addLeft();
			}
			sol[qr[i].index] = counter[qr[i].k];
		}
		for(int i = 0; i < q; i++){
			cout<<sol[i]<<endl;//write(sol[i]);
		}
	}
}
