#include <bits/stdc++.h>
using namespace std;

int main() {
int n;
int t;
  int a;
  cin>>t;
  for(int i=0;i<t;i++){
  cin>>n;
    long long sum=0;
    for(int j=0;j<n;j++){
        cin>>a;
       sum+=(long long)a;
    }

    if(sum%2==0){
      cout << "YES" <<endl;
    }
    else cout << "NO" <<endl;
  }




  return 0;
}