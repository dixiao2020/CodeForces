#include<bits/stdc++.h>
using namespace std;

int main(){

int t,a,n,x;
cin>>t;

for(int i=0;i<t;i++){
    vector<int>aVec;
    cin>>n>>x;
    for(int j=0;j<n;j++){
        cin>>a;
        aVec.push_back(a);
    }
    vector<long long>bVec;
    for(int k=1;k<=n;k++){
        long long sum=0;
        long long maxVal=LLONG_MIN;
        for(int j=0;j<n;j++){
            sum+=aVec[j];
            if(j>=k){
                sum-=(long long)aVec[j-k];
            }
            if(j>=k-1){
                maxVal=max(maxVal,sum);
            }
        }
        bVec.push_back(maxVal);
    }
     
      for(int k=0;k<=n;k++){
         long long maxVal=0;
        for(int j=0;j<n;j++){
            if(k==0){
              maxVal=max(maxVal,bVec[j]);
            }
          else if(k!=0) maxVal= max(maxVal,min(j+1,k)*x+bVec[j]);

         }
         if(k!=n) cout << maxVal<<" ";
         else cout << maxVal<<endl;
      }
     
    

}



    return 0;
}
