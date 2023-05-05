#include<bits/stdc++.h>
using namespace std;
static bool compare(vector<int>&, vector<int>&);
int main(){
int t,a,m;
cin>>t;

for(int i=0;i<t;i++){
    cin>>m;
    int idx=1;
    long long ans=0;
    vector<vector<int>>aVec;
    for(int j=0;j<m;j++){
        cin>>a;
        if(a<idx){
            aVec.push_back({idx,a});
        }
        idx++;
    }
    sort(aVec.begin(),aVec.end(),compare);
    vector<int>vals;
    for(int i=0;i<aVec.size();i++){
        vals.push_back(aVec[i][1]);
    }
    for(int i=0;i<aVec.size();i++){
        int target = aVec[i][0];
        auto itr = upper_bound(vals.begin(),vals.end(),target);
        auto cnt =itr-vals.begin();
        ans+=(long long) aVec.size()-cnt;
    }
    cout << ans <<endl;
}


    return 0;
}
 static bool compare(vector<int>&A, vector<int>&B){
    if(A[1]==B[1])  {
        return A[0]<B[0];
    }
    return A[1]<B[1];
}