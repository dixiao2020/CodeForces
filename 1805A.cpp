#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
int t,size;
cin>>t;
for(int i=0;i<t;i++){
   
    cin>>size;
  //   cout << size <<endl;
    int a;
    int sum=0;
  //  vector<int>arr;
    for(int j=0;j<size;j++){
       cin>>a;
       sum^=a;
    }
    if(size%2==1){
        cout<<sum <<endl;
    }
    if(size%2==0){
        if(sum!=0) cout<<-1<<endl;
        else cout<<0<<endl;
    }
  
}





    return 0;
}