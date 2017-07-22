    #include<iostream>
    #define INF 0x7fffffff;
    using namespace std;
    int main(){
        int t;
        cin>>t;
        while(t--){
            int n;
            cin>>n;
            int arr[n][7];
            for(int i=0; i<n; i++){
                for(int j =0; j<7; j++){
                    arr[i][j] = 0;
                }
            }
            for(int i=0; i<n; i++){
                int l;
                cin>>l;
                arr[i][0] = l;
                for(int j=0; j<l; j++){
                    int temp;
                    cin>>temp;
                    arr[i][temp]++;
                }
            }
            int ans[n];
            int count4[n],count5[n],count6[n];
            for(int i=0; i<n; i++){
             //   count4[i] = count5[i] = count6[i] = 0;
                ans[i] = arr[i][0];
            }
            for(int i=0; i<n; i++){
                int min = INF;
                int pos = -1;
                int pos2 = -1;
                for(int j=1; j<=6; j++){
                    if(min > arr[i][j]){
                        min = arr[i][j];
                        pos = j;
                    }
                }
                ans[i] += min*4;
                for(int j=1; j<=6; j++){
                    arr[i][j] -= min;
                }
                min = INF;
                for(int j=1; j<=6; j++){
                    if(min > arr[i][j] && j!= pos){
                        min = arr[i][j];
                        pos2 = j;
                    }
                }
                ans[i] += min*2;
                for(int j=1; j<=6; j++){
                    arr[i][j] -= min;
                }
                min = INF;
                for(int j=1; j<=6; j++){
                    if(min > arr[i][j] && j!= pos && j!=pos2){
                        min = arr[i][j];
                    }
                }
                ans[i] += min;
            }
            int max = 0;
            int pos = -1;
            for(int i=0; i<n; i++){
                if(max < ans[i]){
                    max = ans[i];
                    pos = i;
                }
            }
            int flag = true;
            for(int i=0; i<n; i++){
                if(max == ans[i] && pos != i){
                    flag = false;
                }
            }
            if(flag){
                if(pos == 0){
                    cout<<"chef"<<endl;
                }
                else{
                    cout<<pos+1<<endl;
                }
            }
            else{
                cout<<"tie"<<endl;
            }
        }
        return 0;
    } 
