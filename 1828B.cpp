#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
int t,m,a,b;
cin >> t;

for(int i=0;i<t;i++){
    int minVal=INT_MAX;
int maxVal=INT_MIN;
    cin>>m;
    vector<int>aa;
    vector<int>bb;
    for(int j=0;j<m;j++){
        cin>>a;
        aa.push_back(a);
        
    }
    for(int j=0;j<m;j++){
        cin>>b;
        bb.push_back(b);
    }
 

    int idxs=0;
    int idxe=m-1;
    
    int ptr=0;
    while(ptr!=m && aa[ptr]==bb[ptr]){
        
        ptr++;
    }
    idxs=ptr;
    ptr=m-1;
    while(ptr!=-1 &&aa[ptr]==bb[ptr]){
        ptr--;
    }
    idxe=ptr;
    if(idxs==m && idxe==-1){
        cout << 1<<" "<< m <<endl;
        continue;
    }
    for(int w=idxs;w<=idxe;w++){
        minVal=min(minVal, aa[w]);
        maxVal=max(maxVal, aa[w]);
    }
 //   if(i==7) cout << idxs << "--" <<idxe << maxVal<<endl;
    while(idxs!=0 && aa[idxs-1]<=minVal){
        minVal=min(minVal,aa[idxs-1]);
        idxs--;
    }
    while(idxe!=m-1 && aa[idxe+1]>=maxVal){
       maxVal=max(maxVal, aa[idxe+1]);
        idxe++;
        
    }
    cout << idxs+1 << " "<<idxe+1 <<endl;

}


    return 0;
}
