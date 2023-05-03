#include<bits/stdc++.h>
using namespace std;

int main(){

int t,m,a;
cin>>t;
for(int i=0;i<t;i++){
    cin>>m;
  
    
    vector<int>aVec;
    vector<int>bVec;
    for(int j=0;j<m;j++){
        cin>>a;
        aVec.push_back(a);
    }
    for(int k=0;k<m-1;k++){
        bVec.push_back(aVec[k+1]-aVec[k]);
    }
    if(m%2==1) {
        cout<< "YES"<<endl;
        continue;
    }
  
    long long sum=0;
    for(int k=0;k<bVec.size();k+=2){
        sum+=(long long)bVec[k];
    }
    if(sum>=0){
        cout <<"YES"<<endl;
    }
    else cout << "NO"<<endl;
}


    return 0;
}