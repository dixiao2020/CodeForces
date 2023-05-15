#include<bits/stdc++.h>
using namespace std;
int main(){
int t, n, k;

cin>>t;
vector<int>arr;
for(int i=0;i<30;i++){
    arr.push_back((i+2)*(i+1)/2);
}

for(int i=0;i<t;i++){
    cin>>n>>k;
    
    int NumNeg = n*(n+1)/2-k; // number of negative subarr sum;
    if(NumNeg==0){
        for(int j=0;j<n;j++){
            if(j!=n-1) cout << 1 << " ";
            else cout << 1 << endl;
        }
      //  cout << i <<endl;
       continue;
    }
    auto itr = lower_bound(arr.begin(),arr.end(),NumNeg);
    int index = itr-arr.begin();
    if(arr[index]==NumNeg){
        for(int j=1;j<=index+1;j++){
           if(j!=n) cout << -2 <<" ";
           else cout << -2<<endl;
        }
        for(int j=index+2;j<=n;j++){
            if(j!=n) cout << 2*(index+1)+1<<" ";
            else cout << 2*(index+1)+1<<endl;
        }
    }
   else {
        int remain = NumNeg-arr[index-1];
        for(int j=0;j<index;j++){
            cout << -2 <<" ";
        }
        if(index!=n-1)cout<< (index-remain)*2+1 <<" ";
        else cout << (index-remain)*2+1 <<endl; 
        for(int j=index+1;j<n;j++){
            if(j!=n-1) cout << index*2+1 <<" ";
            else cout << index*2+1<<endl;
        }
   }



}

    return 0;
}