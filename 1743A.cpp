#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int tc, nc, vals;
vector<int>ans;
int main(){
cin>>tc;
for(int i=0;i<tc;i++){
    cin >>nc;
    for(int j=0;j<nc;j++){
        cin>>vals;
    }
    if(nc>=9){
        ans.push_back(0);
    }
    else{
        ans.push_back((10-nc)*(9-nc)*3);
    }

}

   for(int i=0;i<tc;i++){
    cout << ans[i]<<endl;
   }


    return 0;
}
