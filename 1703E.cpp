#include<bits/stdc++.h>
using namespace std;
int main(){

int t,m;
string a;
cin>>t;
for(int i=0;i<t;i++){
   cin>>m;
   int ans=0;
   vector<vector<int>>mat(m,vector<int>(m,0));
   vector<vector<bool>>visited(m,vector<bool>(m,false));
   if(m%2==1) visited[m/2][m/2]=true;
   
   for(int j=0;j<m;j++){
    cin>>a;
    for(int k=0;k<m;k++){
        
        mat[j][k]=a[k]-'0';
    //   cout << mat[j][k]<<" ";
    }
    //cout << endl;
   }
    for(int j=0;j<m;j++){
        for(int k=0;k<m;k++){
        
            if(!visited[j][k]){
                int cnt=0;
                visited[j][k]=true;
                visited[k][m-1-j]=true;
                visited[m-1-j][m-1-k]=true;
                visited[m-1-k][j]=true;
                if(mat[j][k]==0){
                    cnt++;
                }
                if(mat[k][m-1-j]==0) cnt++;
                if(mat[m-1-j][m-1-k]==0)cnt++;
                if(mat[m-1-k][j]==0) cnt++;
               
                ans+=cnt<4-cnt? cnt:4-cnt;
            }
        }
    }
    cout<<ans <<endl;
}




return 0;
}