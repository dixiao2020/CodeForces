#include<bits/stdc++.h>
using namespace std;

int main(){
int t,n,m,a;
cin >> t;
for(int i=0;i<t;i++){
    int ans=0;
   cin>>n; // nums
   cin>>m; // num of segment
   vector<int>arr;
   
    vector<int>diff;
   for(int j=0;j<m;j++){
    cin>>a;
    arr.push_back(a);
   }
  sort(arr.begin(),arr.end());
   for(int j=0;j<m-1;j++){
    diff.push_back(arr[j+1]-arr[j]-1);
   }
   diff.push_back(arr[0]-1+n-arr[m-1]);
   sort(diff.begin(),diff.end(),greater<int>());
     
    int ptr=0;
    int steps=0;
 //   for(int i=0;i<diff.size();i++){
 //       cout << diff[i]<<" ";
 //  }
 //   cout << endl;
    int val=diff[ptr];
    while(ptr!=diff.size() && val>0){
    //    cout << diff[ptr] <<"before " <<steps*2<<endl;
       val= diff[ptr]-2*steps;
   ////     cout << diff[ptr]<<" after "<<steps*2 <<endl;
        if(steps%2==0 && val>0){
            ans+=1;
        }
        if(steps%2==1 && val>0){
            ans+=val;
        }
        
 //cout << steps << " " << ans <<" " << diff[ptr]<< endl;
     if(steps%2==1) ptr++;
        steps++;
     
      
    }
        cout << n-ans <<endl;
}

    return 0;
}