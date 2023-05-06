#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,m;
    string a,b;
    cin>>t;
    
    for(int i=0;i<t;i++){
        int cnt=0;
        vector<int>aVec;
        cin >> m;
        cin>>a;
        cin>>b;
       // cout << m <<endl;
  
       
        for(int j=m-1;j>=1;j--){
           
            if(a[j]==b[j]){
                continue;
            }
            else{
                if(a[0]==b[j]){
                    a[0]=('1'-a[0])+'0';
                    aVec.push_back(1);
                    cnt++;
                }

                aVec.push_back(j+1);
                cnt++;
                for(int k=0;k<=j;k++){
                    a[k]=('1'-a[k])+'0';
                }
          
                for(int k=0;k<=j/2;k++){
                    char temp = a[k];
                    a[k]=a[j-k];
                    a[j-k]=temp;
                }
              

            }
          //   cout << a <<endl;
        }
        if(a[0]!=b[0]){
            aVec.push_back(1);
            cnt++;
        }
 //  cout << a << "--"<<a.length() <<" "<< b <<endl;
        cout << cnt <<" ";
        for(int i=0;i<aVec.size();i++){
           if(i!=aVec.size()-1) cout << aVec[i] <<" ";
           else cout << aVec[i];
        }
       cout <<endl;
    }



    return 0;
}