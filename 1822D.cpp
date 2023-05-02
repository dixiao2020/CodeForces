#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){

int t,n;
cin>> t;
for(int j=1;j<=t;j++){
    cin>>n;
if(n==1){
    cout << 1 <<endl;
    continue;
}
if(n%2==1){
    cout << -1 <<endl;
    continue;
}
vector<int>aVec(n,0);
for(int i=1;i<=n/2;i++){
    aVec[i*2-2]=i;
    aVec[i*2-1]=n+1-i;
}
cout << n <<" ";
for(int i=0;i<n-1;i++){
    int val = aVec[i+1]-aVec[i];
    if(i!=n-2){
        if(val>0){
        cout <<val <<" "; 
    }
    else cout << val+n<<" ";
    }
    else {
        if(val>0){
            cout<<val;
        }
        else cout << val+n;
    }
    
}
 cout <<endl;
}



    return 0;
}