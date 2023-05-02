#define modulo 1000000007
#define aa 37
#define bb 53
#include<string>
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
vector<int> getPrefix(string &, int);
vector<int>getPower(int,int);
int main(){
    int ans=0;
    vector<int>prefixaaa;
    vector<int>prefixbaa;
    vector<int>prefixabb;
    vector<int>prefixbbb;
    vector<int>powera;
    vector<int>powerb;
    vector<int>aVec;
    string a;
    string b;
    cin>> a;
    cin>>b;
    int m = a.length();
    int n = b.length();
    
    int k = __gcd(m,n);
    for(int i=1;i<=k;i++){
        if(k%i==0){
            aVec.push_back(i);
        }
    }
    
    powera=getPower(aa,k);
    powerb=getPower(bb,k);
     prefixaaa=getPrefix(a,aa);
     prefixbaa=getPrefix(b,aa);
     prefixabb=getPrefix(a,bb);
     prefixbbb=getPrefix(b,bb);

     for(int i=0;i<aVec.size();i++){
  //      cout << aVec[i]<<endl;
        bool flag=true;
        int winSize = aVec[i];
        int hvaaa=prefixaaa[winSize-1];
        int hvbaa=hvaaa;
        int hvabb=prefixabb[winSize-1];
        int hvbbb=hvabb;
        int caaa=hvaaa;
        int cbaa=hvbaa;
        int cabb=hvabb;
        int cbbb=hvbbb;
       // cout << hvaaa << " " <<hvbaa <<" " <<hvabb <<  " " <<hvbbb <<endl;
        for(int j=0;j<m;j+=winSize){
            
            flag=flag && hvaaa==prefixaaa[j+winSize-1];
            flag=flag && hvabb==prefixabb[j+winSize-1];
            hvaaa=(((long long)hvaaa*powera[winSize])%modulo+caaa)%modulo;
            hvabb=(((long long)hvabb*powerb[winSize])%modulo+cabb)%modulo;
        }
        for(int j=0;j<n;j+=winSize){
           
            flag = flag && hvbaa==prefixbaa[j+winSize-1];
            flag = flag && hvbbb==prefixbbb[j+winSize-1];
            hvbaa=(((long long)hvbaa*powera[winSize])%modulo+cbaa)%modulo;
            hvbbb=(((long long)hvbbb*powerb[winSize])%modulo+cbbb)%modulo;
        }
     //   cout << flag <<endl;
        if(flag) ans++;
     }

     cout << ans <<endl;
    return 0;
}

vector<int> getPrefix(string &s, int base){
      int m = s.length();
        vector<int>ans;
       long long h = s[0]-'a'+1;
       ans.push_back(h);
        for(int i=1;i<m;i++){
            h=((h*(long long)base)%modulo+s[i]-'a'+1)%modulo;
            ans.push_back(h);
        }
    
        return ans;
}
vector<int>getPower(int base,int ub){
        vector<int>ans;
        long long h = 1;
        ans.push_back(h);
        for(int i=0;i<=ub;i++){
            h=(h*(long long)base)%modulo;
            ans.push_back(h);
        }
        return ans;
}

