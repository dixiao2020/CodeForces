#include<bits/stdc++.h>
using namespace std;
int main(){
int t,m,a;
cin>>t;

for(int i=0;i<t;i++){
    vector<int>aVec;
    cin>>m;
    int minVal=INT_MAX;
    for(int j=0;j<m;j++){
        cin>>a;
        aVec.push_back(a);
        minVal=min(minVal,a);
    }
    vector<int>bVec=aVec;
    sort(aVec.begin(),aVec.end());
   
    int val=-1;
    bool first_call=false;

    for(int j=0;j<m;j++){
        if(aVec[j]!=bVec[j]){
            if(!first_call){
                val = bVec[j];
                first_call=true;
            }
           val= __gcd(bVec[j],val);
        }
    }
    if(val==-1 || minVal==__gcd(val,minVal)){
        cout << "YES"<<endl;
    }
    else cout<< "NO" <<endl;
}


    return 0;
}