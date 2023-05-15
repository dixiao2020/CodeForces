#define modulo 1000000007
#include<bits/stdc++.h>
using namespace std;


int main(){
int t,n;
cin>>t;
vector<int>pal;



for(int i=1;i<=40000;i++){
   string temp = to_string(i);
   bool flag=true;
    for(int j=0;j<temp.size()/2;j++){
        if(temp[j]!=temp[temp.size()-j-1]){
            flag=false;
            break;
        }
    }  
    if(flag) pal.push_back(i);
}
   int size = pal.size();
   
long long **dp;
dp = new long long* [40000];
for(int i=0;i<40001;i++){
    dp[i]= new long long [size];
    for(int j=0;j<size;j++){
        dp[i][j]=0;
    }
}
 //cout << "yes"<<endl;
  
    for(int j=1;j<40001;j++){
        dp[j][0]=1;
        for(int k=1;k<size;k++){
            dp[j][k]=0;
        }
    }
  
    for(int k=0;k<size;k++){
        dp[0][k]=1;
      //  dp[1][k]=1;
    }
  
    for(int j=1;j<40001;j++){
        for(int k=1;k<size;k++){
           if(j>=pal[k]) dp[j][k]=(dp[j][k-1]+dp[j-pal[k]][k])%modulo;
           else {
          
              dp[j][k]=dp[j][k-1];
            }
           
        }
      
    }


for(int i=0;i<t;i++){
    cin>>n;
   
    
        cout << dp[n][size-1]<<endl;

}



    return 0;
}


