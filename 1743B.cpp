#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<vector<int>>ans;
int tc,n;
int main(){
 cin>>tc;
 ans = vector<vector<int>>(tc);
 for(int i=0;i<tc;i++){
    cin>>n;
    vector<int>temp(n,0);
    int val;
    for(int j=0;j<n;j++){
        if(j%2==0) {
            temp[j]=j/2+1;
            val = temp[j];
            }
    }
    for(int j=n-1;j>=0;j--){
        if(j%2==1){
            val++;
            temp[j]=val;
            
        }
    }
    ans[i]=temp;
 }

for(int i=0;i<tc;i++){
    for(int j=0;j<ans[i].size();j++){
        cout<< ans[i][j]<< " ";
    }
    cout <<endl;
}


    return 0;
}