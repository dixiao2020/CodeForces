#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    string s;
    cin >> t;
    for(int i=0;i<t;i++){
        vector<string>aVec;
        for(int j=0;j<9;j++){
            cin>>s;
            aVec.push_back(s);
        }
        for(int j=0;j<9;j++){
            for(int k=1;k<=9;k++)
            if(k+'0'!=aVec[j][j%3*3+j/3]) {
                aVec[j][j%3*3+j/3]=k+'0';
                break;
                }
              
        }
       
        for(int j=0;j<9;j++){
            cout<<aVec[j]<<endl;
        }


    }


    return 0;
}