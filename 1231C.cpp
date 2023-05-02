#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
int m, n,matel;
cin >>m;
cin>>n;
vector<vector<int>>dir{{-1,0},{0,-1},{1,0},{0,1}};
vector<vector<int>>matrix(m,vector<int>());

for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cin>>matel;
        matrix[i].push_back(matel);
    //    cout << matel<<" ";
    }
   // cout <<endl;
}
int sum =0;
  
for(int i=m-1;i>=0;i--){
    for(int j=n-1;j>=0;j--){
       
            int minVal=INT_MAX;
            int maxVal=INT_MIN;
            for(int k=0;k<=1;k++){
                int x =i+dir[k][0];
                int y = j+dir[k][1];
                if(x!=-1 && y!=-1 && x!=m && y!=n){
                    if(matrix[x][y]!=0){
                        maxVal=max(maxVal,matrix[x][y]);
                    }
                }
            }
           
            for(int k=2;k<=3;k++){
                int x = i+dir[k][0];
                int y = j+dir[k][1];
                if(x!=-1 && y!=-1 && x!=m && y!=n){
                    minVal=min(minVal,matrix[x][y]);
                }
            }
            if(minVal-1>maxVal) {
            if(matrix[i][j]==0)    matrix[i][j]=minVal-1;
            else if(matrix[i][j]<=maxVal||matrix[i][j]>=minVal){
                cout <<-1 <<endl;
                return 0;
            }
                sum+=matrix[i][j];
                }
            else {
                cout << -1 <<endl;
                return 0;
            }
        }
    
    
}



  cout << sum <<endl;

    return 0;
}