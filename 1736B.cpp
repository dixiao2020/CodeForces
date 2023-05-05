#include<bits/stdc++.h>

using namespace std;
int main(){

int t,m,a;
cin>>t;
for(int i=0;i<t;i++){
    cin>>m;

    vector<int>arr(m,0);
    for(int j=0;j<m;j++){
        cin>>a;
        arr[j]=a;
      //  cout << arr[i]<<endl;
    }
    vector<int>brr(m+1,0);
    for(int j=0;j<m+1;j++){
        if(j==0){
            brr[j]=arr[j];
        }
      else  if(j==m){
            brr[j]=arr[j-1];
        }
        else brr[j]=lcm(arr[j-1],arr[j]);
     //   cout << brr[j]<<endl;
    }
    bool flag=true;
    for(int j=0;j<m;j++){
      
        if(gcd(brr[j],brr[j+1])>arr[j]){
            flag=false;
            break;
        }
    }
    if(!flag) cout<<"NO"<<endl;
    if(flag) cout <<"YES"<<endl;
}


    return 0;
}