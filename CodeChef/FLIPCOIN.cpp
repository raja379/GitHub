    #include<iostream>
    #include<cmath>
    using namespace std;
    /*int build_recur(int sg[], int size, int i){
    	int m = (size+1)/2;
    	if(m-1 <= i && i <= size-1){
    		return sg[i];
    	}
    	sg[i] = build_recur(sg,size,2*i+1) + build_recur(sg,size,2*i+2);
    	return sg[i];
    }
    void build(int sg[],int a[],int n,int size){
    	for(int i=0, j = size/2; i<n; i++,j++){
    		sg[j] = a[i];
    	}
    	build_recur(sg,size,0);
    }*/
    int update(int sg[], int check[], int size, int l, int r, int i,int left[],int right[]){
    	if(check[i]%2 == 1){
    		check[i] = 0;
    		sg[i] = -left[i]+right[i]+1-sg[i];
    		if((2*i+1) < size) check[2*i+1]++;
    		if((2*i+2) < size) check[2*i+2]++;
    	}
    	if(left[i] < l && right[i] < l || left[i] > r && right[i] > r){
    		return sg[i];
    	}
    	if(left[i] >= l && right[i] <= r){
    		sg[i] = -left[i]+right[i]+1-sg[i];
    		if(2*i+1 < size) check[2*i+1]++;
    		if(2*i+2 < size) check[2*i+2]++;
    		return sg[i];
    	}
    	int p,q;
    	if(2*i+1 < size){
    		p = update(sg,check,size,l,r,2*i+1,left,right);
    	}
    	if(2*i+2 < size){
    		q = update(sg,check,size,l,r,2*i+2,left,right);
    	}
    	sg[i] = p+q;
    	return sg[i];
    }
    int query(int sg[], int check[], int size, int l, int r, int i,int left[],int right[]){
    	if(check[i]%2 == 1){
    		check[i] = 0;
    		sg[i] = -left[i]+right[i]+1-sg[i];
    		if((2*i+1) < size) check[2*i+1]++;
    		if((2*i+2) < size) check[2*i+2]++;
    	}
    	if(left[i] < l && right[i] < l || left[i] > r && right[i] > r){
    		return 0;
    	}
    	if(left[i] >= l && right[i] <= r){
    		return sg[i];
    	}
    	int p,q;
    	if(2*i+1 < size){
    		p = query(sg,check,size,l,r,2*i+1,left,right);
    	}
    	if(2*i+2 < size){
    		q = query(sg,check,size,l,r,2*i+2,left,right);
    	}
    	return p+q;
    }
    void calc(int left[],int right[],int size){
    	left[0] = 0;
    	int m = (size+1)/2;
    	int temp = (size+1)/2;
    	right[0] = m-1;
    	int j = 0;
    	for(int i = 0; i < size; i++){
    		left[i] = j;
    		right[i] = left[i] + temp - 1;
    		j += temp;
    		if(j >= m){
    			j = 0;
    			temp >>= 1;
    		}
    	}
    }
    int main(){
    	int n,q;
    	cin>>n>>q;
    	int temp = (int)log2(n);
    	if(log2(n) != (float)temp) temp++;
    	int m = pow(2,temp);
    	int size = 2*m - 1;
    	int a[n],sg[size],check[size],left[size],right[size];
    	calc(left,right,size);
    	for(int i=0; i<size; i++){
    		sg[i] = check[i] = 0;
    	}
    	for(int i=0; i<q; i++){
    		int opt,l,h;
    		cin>>opt>>l>>h;
    		if(opt == 0){
    			update(sg,check,size,l,h,0,left,right);
    		}else{
    			cout<<query(sg,check,size,l,h,0,left,right)<<endl;
    		}
    	}
    } 
