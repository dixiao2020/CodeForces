#include<bits/stdc++.h>
using namespace std;
int main(){
int t,m,k;
cin>>t;
for(int i=0;i<t;i++){
    cin>>m>>k;
    vector<long long>aVec;
    for(long long j=2;j<=m;j++){
        aVec.push_back(j*(j-1)/2);
    }
    auto itr = lower_bound(aVec.begin(),aVec.end(),(long long)k);
    auto index = itr-aVec.begin();
    long long val =-aVec[index]+k;
    string s="";
    for(int j=0;j<m;j++){
        s.push_back('a');
    }
    if(val==0){
        s[m-1-index]='b';
        s[m-2-index]='b';
    }
    else{
        val = (long long)k-aVec[index-1];
        s[m-2-index]='b';
        s[m-val]='b';
    }
    cout << s <<endl;
}

    return 0;
}