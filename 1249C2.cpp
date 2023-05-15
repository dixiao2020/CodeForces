#include<bits/stdc++.h>

using namespace std;

int main(){
long long prod=1;
int t;
long long a;
vector<long long>power;
for(int i=0;i<=38;i++){
  power.push_back(prod);
  prod*=3;
    
}
cin>>t;
for(int i=0;i<t;i++){
  cin>>a;
   vector<int>aVec;
   long long temp=a;
  while(temp!=0){
    int digit =temp%3;
    aVec.push_back(digit);
    temp/=3;
  }
int index =-1;
    for(int j=0;j<aVec.size();j++){
    //   if(i==7) cout << aVec[j]<<endl;
        if(aVec[j]==2){
            index=j;
        }
    }
  //  if(i==7) cout << index<<"-=" <<endl;
   
    if(index==-1) {
        cout << a <<endl;
        continue;
        }
    int idx=-1;
    for(int j=index;j<aVec.size();j++){
        if(aVec[j]==0){
            idx=j;
            break;
        }
    }
    if(idx==-1){
        
        cout << power[(int)aVec.size()]<<endl;
    }
    else{
        long long ans=power[idx];
        for(int j=idx;j<aVec.size();j++){
            if(aVec[j]!=0) ans+=power[j];
        }
        cout << ans <<endl;
    }

}


    return 0;
}