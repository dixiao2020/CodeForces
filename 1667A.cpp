#include<bits/stdc++.h>

using namespace std;

int main(){
    int m,a;
    cin>>m;
    vector<long long>arr;
    for(int i=0;i<m;i++){
        cin>>a;
        arr.push_back((long long)a);
    }
    
    long long ans=LLONG_MAX;
    for(int i=0;i<m;i++){
        long long cnt=0;
        long long val=0;
        for(int j=i-1;j>=0;j--){
            if(j==i-1){
                cnt++;
                val=arr[j];
            }
            else{
              
                    cnt+= ceil(((long double)val+1)/arr[j]);
                    val = ceil(((long double)val+1)/arr[j])*arr[j];
                    
            }
        }
        for(int j=i+1;j<m;j++){
            if(j==i+1){
                cnt++;
                val=arr[j];
            }
            else{
                 
                    cnt+= ceil(((long double)val+1)/arr[j]);
                    val = ceil(((long double)val+1)/arr[j])*arr[j];
                    
            }
        }


        ans=min(ans,cnt);
    }
         cout << ans <<endl;

    return 0;
}