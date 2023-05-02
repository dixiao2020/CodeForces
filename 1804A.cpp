#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
int t,a,b;
cin>>t;
for(int i=0;i<t;i++){
    cin>>a;
    cin>>b;
 //   cout << a <<b <<endl;
    if(abs(abs(a)-abs(b))<=1){
        cout<< abs(a)+abs(b) <<endl;
    }
    else cout << abs(a)+abs(b)+abs(abs(a)-abs(b))-1 <<endl;

}


return 0;

}




