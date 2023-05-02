#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void factor(int,unordered_map<int,int>&);
int main(){
int t,m,val;
cin>>t;

for(int i=0;i<t;i++){
    cin>>m;
    
    unordered_map<int,int>mp;
    for(int j=0;j<m;j++){
        cin>>val;
        factor(val,mp);
    //    cout << val <<endl;
    }
    int ans=0;
int cnt=0;
    for(auto itr = mp.begin();itr!=mp.end();itr++){
    //    cout << itr->first << itr->second <<endl;
        if(itr->second>=2){
            ans+=itr->second/2;
            itr->second=itr->second-itr->second/2*2;
           
            
        }
        if(itr->second==1) cnt++;
    }

cout << ans+cnt/3 <<endl;
}

    return 0;
}
void factor(int n, unordered_map<int,int>&mp){
  
    while(n%2==0){
        n/=2;
        mp[2]++;
    }
   

    for(int i=3;i*i<=n;i+=2){
        while(n%i==0){
            n/=i;
            mp[i]++;
        }
    }
    if(n!=1)    mp[n]++;
}