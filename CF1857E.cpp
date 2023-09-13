#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  int m;
  int a;
  cin >> t;
  for(int i=0;i<t;i++){
    cin>>m;
    vector<vector<int>>aVec;
    for(int j=0;j<m;j++){
      cin>>a;
      aVec.push_back({a,j});
    }
    sort(aVec.begin(),aVec.end());

    
    vector<long long>prefix;
    long long sum =0;
    for(int j=0;j<m;j++){
      sum+=(long long)aVec[j][0];
      prefix.push_back(sum);
    }
    vector<long long>ans(m,0);
    for(int j=0;j<m;j++){
      
      ans[aVec[j][1]]+=(long long)aVec[j][0]*(j+1)-prefix[j]+j+1;
      ans[aVec[j][1]]+=(long long)sum-prefix[j]-(long long)aVec[j][0]*(m-j-1)+m-j-1;
    }
    for(int j=0;j<m;j++){
      cout << ans[j]<<" ";
    }
    cout <<endl;
  }

  return 0;
}