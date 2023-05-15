#include<bits/stdc++.h>
using namespace std;
int main(){
int t,m,a;
cin>>t;

for(int i=0;i<t;i++){
    long long ans=0;
    cin>>m;
    vector<int>aVec;
    for(int j=1;j<=m;j++){

        cin>>a;
        aVec.push_back(a);

    }

    long long left=0;
    long long right =0;
 
    while(right!=aVec.size()){
      
        while(right-left+1>aVec[right]){
       
          
            left++;
        }
   
          ans+=right-left+1;

        right++;
    }
    


cout<<ans<<endl;

}
    return 0;
}