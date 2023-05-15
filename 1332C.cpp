#include<bits/stdc++.h>
using namespace std;
void DFS(string & , int , int ,vector<bool>&v, int&,vector<int>&, int&);
int main(){
string s;
int t,m,k;
cin >> t;
for(int i=0;i<t;i++){
    cin>>m>>k;
    cin>>s;
 //   cout << m <<k << s <<endl;
    vector<bool>visited(m,false);
    int ans=0;
    for(int j=0;j<m;j++){
        if(!visited[j]){
            vector<int>dp(26,0);
            int cnt=0;
            int maxVal=0;
            DFS(s,j,k,visited,cnt,dp,maxVal);
            ans+=cnt-maxVal;
        }
    } 

    cout << ans <<endl;
}





    return 0;
}


void DFS(string & s, int v, int k,vector<bool>&visited, int&cnt,vector<int>&dp, int& maxVal){
    visited[v]=true;
    cnt++;
  //  cout << v <<endl;
    dp[s[v]-'a']++;
    maxVal=max(maxVal,dp[s[v]-'a']);
    if(v+k<s.length()&&!visited[v+k]){
        
        DFS(s,v+k,k,visited,cnt,dp,maxVal);
        visited[v+k]=true;
    }
    if(!visited[s.length()-1-v]){
        
            DFS(s,s.length()-1-v,k,visited,cnt,dp,maxVal);
        visited[s.length()-1-v]=true;;
    }


}