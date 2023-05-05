#include<bits/stdc++.h>
using namespace std;
bool isTrue(vector<int>&,int,int);
int main(){
  int t,m,a;
  cin>>t;
  
  for(int i=0;i<t;i++){
    cin>>m; // length
    vector<int>aVec;
    for(int j=0;j<m;j++){
       cin>>a;
        aVec.push_back(a);
    }
    for(int j=1;j<=m;j++){
        int left = 1;
        int right = j;
        int mid;
        if(j<=aVec[0]){
            if(j!=m){
                cout << j<<" ";
              
            }
            else{
                cout<<j;
            }
            continue;
        }
        while(left<right){
            mid=(left+right)/2;
            if(isTrue(aVec,mid,j)){
                left=mid+1;
            }
            else right=mid;
        }
           if(j!=m){
            cout << left-1<<" ";
           }
           else cout << left-1;
    }
    cout <<endl;
   
  }

    return 0;
}

bool isTrue(vector<int>&aVec, int target,int bound){
     auto itr = lower_bound(aVec.begin(),aVec.end(),target);
     auto index = itr-aVec.begin();
     if(index+target <=bound){
        return true;
     }
     return false;
}