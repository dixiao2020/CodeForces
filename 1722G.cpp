#include<bits/stdc++.h>

using namespace std;
int main(){
    int t,m;
    cin >>t;
    for(int i=0;i<t;i++){
        cin>>m;
        vector<int>aVec;
        int sum=0;
        for(int j=0;j<m;j++){
            aVec.push_back(j+1);
            sum^=aVec[j];
        } 
        if(sum!=0) {
            int digits =0;
            int temp = aVec[m-1];
        
            while(temp!=0){
                temp=temp>>1;
                digits++;
            }
            sum^=aVec[m-1];
            sum^=aVec[m-2];
           if(sum==0){
            for(int j=0;j<m-2;j++){
                aVec[j]=j;
                sum^=j;
            }
           }
            aVec[m-2]=1<< (digits+1);
           
            aVec[m-1]=aVec[m-2]^sum;
           
           
        }
          for(int j=0;j<m;j++){
             if(j!=m-1)   cout << aVec[j] <<" ";
             else cout <<aVec[j]<<endl;
            }
            sum=0;
          // fortesting!
          // for(int i=0;i<aVec.size();i++){
       //         sum^=aVec[i];
        //    }
        //    cout << sum <<endl;

    }

    return 0;
}