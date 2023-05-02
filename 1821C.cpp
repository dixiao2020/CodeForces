#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
int main(){
int t;
string s;
cin >>t;
for(int i=0;i<t;i++){
    cin>>s;
    int cnt=0;
    int minVal=INT_MAX;
    for(int j=0;j<26;j++){
        char var = j+'a';
        int first=-1;
        int second=-1;
        int maxVal=0;
    
        for(int k=0;k<s.length();k++){
            if(s[k]==var){
                first=second;
                maxVal=max(maxVal,k-first-1);
                second=k;
            }
        }
        maxVal=max(maxVal,(int)s.length()-second-1);
        minVal=min(minVal,maxVal);
    }
    while(minVal!=0){
        minVal>>=1;
        cnt++;
    }
    cout<<cnt<<endl;
}





    return 0;
}