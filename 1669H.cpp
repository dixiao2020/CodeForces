#include<bits/stdc++.h>
using namespace std;

int main(){

    int t,n,k,a;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        cin>>k;
    
        vector<int>aVec(31,0);
        for(int j=0;j<n;j++){
            cin>>a;
            int step=0;
            while(a!=0){
                if((a&1)==1) aVec[step]++;
                a>>=1;
                step++;
            }
        }
        int ans=0;
        for(int j=30;j>=0;j--){
            int val =n-aVec[j];
            if(val<=k){
               k-= val;
                ans+=1<<j;
            }
            else continue;
        }
        cout << ans <<endl;
    }

    return 0;
}