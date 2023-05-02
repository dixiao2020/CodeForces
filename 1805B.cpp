#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){

int t,size;
cin >>t;
for(int i=0;i<t;i++){
    cin>>size;
    string temp="";
    char a;
    for(int j=0;j<size;j++){
        cin>>a;
        temp.push_back(a);
    }
    int index=-1;
    int minVal=INT_MAX;
    for(int i=0;i<temp.size();i++){
        if(temp[i]-temp[0]<=0 && minVal>=temp[i]-'a'){
            minVal=temp[i]-'a';
            index=i;
        }
    }
    if(index==-1) cout << temp <<endl;
    else {
        for(int i=index;i>=1;i--){
            temp[i]=temp[i-1];
        }
        temp[0]=minVal+'a';
        cout << temp <<endl;
    }
}


    return 0;
}