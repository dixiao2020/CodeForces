#include<bits/stdc++.h>
using namespace std;
long long gVal(vector<long long>&, long long);
long long getVal(vector<vector<long long>>&, vector<vector<bool>>&, int , int);
int main(){

    int t,m,n,a;
    cin>>t;
    
    for(int i=0;i<t;i++){
        cin>>m>>n;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        vector<vector<long long>>aVec(m,vector<long long>(n,0));
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                cin>>a;
                aVec[j][k]=(long long)a;
            }
        }
        long long ans=0;
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
               if(!visited[j][k]) {
                ans += getVal(aVec,visited,j,k);
               }
            }
        }
        cout << ans <<endl;

    }

    return 0;
}


long long getVal(vector<vector<long long>>&grid,vector<vector<bool>>&visited,int x, int y){
    int m = grid.size();
    int n = grid[0].size();
    long long target=0;
    int x1 = m-1-x;
    int y1 =n-1-y;
    long long sum=0; 
    if(x1==x && y1==y) {
        sum=0;
    }
    else if(x1==x && y1!=y){
        target =(grid[x][y]+grid[x][y1])/2;
        sum+=abs(grid[x][y]-target);
        sum+=abs(grid[x][y1]-target);
    }
    else if(x1!=x && y1==y){
        target =(grid[x][y]+grid[x1][y])/2;
        sum+=abs(grid[x][y]-target);
        sum+=abs(grid[x1][y]-target);
    }
    else {
        long long left=LLONG_MAX;
        long long right =LLONG_MIN;
       vector<long long>bVec{grid[x][y],grid[x][y1],grid[x1][y],grid[x1][y1]};
        for(int j=0;j<4;j++){
            left = min(left,bVec[j]);
            right = max(right,bVec[j]);
        }
     
        long long mid,val1,val2,val3;
        while(left<=right){
            mid=(left+right)/2;
             val1 = gVal(bVec,mid-1);
              val2 = gVal(bVec,mid);
              val3 = gVal(bVec,mid+1);
              if(val1>=val2 && val2<=val3) break;
            if(val1>val2 && val2>val3){
                left=mid+1;
            }
            if(val1<val2 && val2<val3){
                right=mid-1;
            }
          
        }  
        long long val = min(val1,val2);
        val = min(val,val3);     
        sum+=val;
    }

    visited[x][y]=true;
    visited[x1][y1]=true;
    visited[x][y1]=true;
    visited[x1][y]=true;
    
    return sum;
}
long long gVal(vector<long long>&cVec,long long target){
    long long sum=0;
    for(int i=0;i<cVec.size();i++){
        sum+=abs(cVec[i]-target);
    }
    return sum;
}

