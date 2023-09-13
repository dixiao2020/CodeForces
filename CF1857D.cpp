#include<bits/stdc++.h>
using namespace std;

int main() {
int m;
int t;
cin>>t;
  int a,b;
  
  for(int i=0;i<t;i++){
    int maxVal=INT_MIN;
    cin>>m;
    int cnt=0;
    vector<int>arr1;
    vector<int>arr2;
    
    for(int j=0;j<m;j++){
      cin>>a;
      arr1.push_back(a);
    }
    for(int j=0;j<m;j++){
      cin>>b;
      arr2.push_back(b);      
    }
    for(int j=0;j<m;j++){
      int val =arr1[j]-arr2[j];
      maxVal=max(maxVal,val);
    }
    vector<int>ans;
    for(int j=0;j<m;j++){
      if(maxVal==arr1[j]-arr2[j]){
        ans.push_back(j+1);
      }
    }
    cout<< (int)ans.size()<<endl;
    for(int j=0;j<ans.size();j++){
      cout << ans[j] <<" ";
    }
    cout <<endl;
  }



  return 0;
}