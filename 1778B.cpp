#include<bits/stdc++.h>
using namespace std;

int main(){
int t,n,m,a,b,d;
cin>>t;

for(int i=0;i<t;i++){
    vector<int>pos;
unordered_map<int,int>mp;
    int step =0;
    cin>>n>>m>>d;
    for(int j=0;j<n;j++){
        cin>>a;
        mp[a]=step;
        step++;
    }
    for(int j=0;j<m;j++){
        cin>>b;
        pos.push_back(mp[b]);
    }
   // for(int j=0;j<pos.size();j++){
    //    cout << pos[j]<<" ";
   // }
  //  cout << endl;
    bool flag =false;
    for(int j=0;j<pos.size()-1;j++){
        if(pos[j+1]>pos[j]+d||pos[j+1]<pos[j]){
            flag=true;
            break;
        }
    }
    if(flag){
        cout << 0<<endl;
        continue;
    }
    int minVal=INT_MAX;
    for(int j=0;j<pos.size()-1;j++){
        if(d<=n-2){
            minVal=min(minVal,pos[j]+d+1-pos[j+1]);
        //   if(i==4) cout << minVal <<endl;
        }
        minVal=min(minVal,pos[j+1]-pos[j]);
    }
    cout << minVal <<endl;

}


    return 0;
}