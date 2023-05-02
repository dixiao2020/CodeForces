#include<bits/stdc++.h>
#include<string>
#include<iostream>
using namespace std;
int main(){
int t,m;
string s;
cin >>t;
for(int i=0;i<t;i++){
cin>>m;
cin>>s;
   if(m%2==1){
    cout << -1 <<endl;
    continue;
   }
   
   unordered_map<char,int>mp; // cnt
   unordered_map<char,int>mpp; //
   bool flag=false; 
    for(int j=0;j<m;j++){
        mp[s[j]]++;
        if(mp[s[j]]>m/2){
            flag=true;
            break;
        }
    }
    if(flag){
        cout << -1 <<endl;
        continue;
    }

    int ans=0;
    for(int j=0;j<m/2;j++){
        if(s[j]==s[m-1-j]){
            mpp[s[j]]+=1;
        }        
    }
    if(mpp.size()==0){
        cout << 0 <<endl;
        continue;
    }
    priority_queue<int>pq;
    for(auto itr = mpp.begin();itr!=mpp.end();itr++){
        pq.push(itr->second);
       // cout << itr->second<< " ";
    }
   // cout << order.size()<< endl;

  while(!pq.empty()){
    int top = pq.top();
    pq.pop();
     if(pq.empty()){
        ans+=top;
        break;
     }
     else{
        int top2 = pq.top();
        top2--;
        top--;
        pq.pop();
        ans++;
        if(top2!=0){
            pq.push(top2);
        }
        if(top!=0){
            pq.push(top);
        }
    
     }

  }

   cout << ans <<endl;
}




    return 0;
}