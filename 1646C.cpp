#include<bits/stdc++.h>
using namespace std;
void backtracking(vector<long long>&,long long&, int & ,int,vector<bool>&,long long , int &);
int main(){

int t;
long long n;
cin>>t;

vector<long long> factorial;
long long prod=1;
for(int i=1;i<=14;i++){
    prod*=(long long)i;
    factorial.push_back(prod);
}
for(int i=0;i<t;i++){
    cin>>n;
    int idx=0;
    for(int j=0;j<factorial.size();j++){
        if(factorial[j]<=n){
            idx=j;
        }
    }
    vector<long long>fact; fact.insert(fact.begin(),factorial.begin(),factorial.begin()+idx+1);
  
   long long sum=0;
   int count=0;
   vector<bool>visited(idx+1,false);
   int minVal=INT_MAX;
   backtracking(fact,sum,count,0,visited,n,minVal);
    cout << minVal<<endl;

}


    return 0;
}
void backtracking(vector<long long>&factor,long long& sum, int &count ,int first,vector<bool>&visited,long long target, int &minVal){
            long long temp = target-sum;
          // if(temp ==17179869184) cout << "yes" <<endl;
          
          if(temp>=0){
              int cnt=0;
             long long copy=temp;
            while(temp!=0){
                if((temp&1)==1) cnt++;
                temp=temp>>1;
            }
       
            minVal=min(minVal,count+cnt);
          }    
      for(int i=first;i<factor.size();i++){
        if(!visited[i]){
            visited[i]=true;
            sum+=factor[i];
            count++;
            backtracking(factor,sum,count,i+1,visited,target, minVal );
            visited[i]=false;
            sum-=factor[i];
            count--;
        }
      }


}