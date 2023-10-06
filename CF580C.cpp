#include <bits/stdc++.h>
using namespace std;
void DFS(int,int,int,list<int>*&,vector<pair<bool,int>>&, vector<int>&);
int main() {

 int n,k;
  cin>>n>>k;
  vector<int>anyCat(n+1,0);
  int a;
  for(int i=1;i<=n;i++){
    cin>>a;
    if(a==1) anyCat[i]=1; 
  }
  int src,dst;
  list<int>*adj = new list<int>[n+1];
  for(int i=1;i<=n-1;i++){
    cin>>src>>dst;
    adj[src].push_back(dst);
    adj[dst].push_back(src);
  }
  vector<pair<bool,int>>dp(n+1,{false,0}); // is this ok to pass? , int number of consecutive cats 
  DFS(1,k,-1,adj,dp,anyCat);
int ans=0;
   for(int i=2;i<=n;i++){
     if(adj[i].size()==1 && !dp[i].first){
       ans++;
     }
   }
  cout<< ans<<endl;

  return 0;
  
}

void DFS( int cur,int k ,int parent, list<int>*&adj,vector<pair<bool,int>>&dp,vector<int>&anyCat){

    if(parent!=-1){
       bool flag = dp[parent].first;
       int val = dp[parent].second;
       if(flag){
         dp[cur].first=true;
         dp[cur].second=0;
       }
      else{
        if(anyCat[cur]==1){
          dp[cur].second=val+1;
          if(val+1>k) dp[cur].first=true;
        }
        else{
          dp[cur].second=0;
        }
      }
    }
  else {
    dp[cur].first =false;
    dp[cur].second= anyCat[cur]?1:0;
  }

    for(auto itr = adj[cur].begin();itr!=adj[cur].end();itr++){
      if(*itr!=parent){
        DFS(*itr,k,cur,adj,dp,anyCat);
      }
    }

  
}