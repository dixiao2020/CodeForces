#include<bits/stdc++.h>

using namespace std;
void backtracking(vector<int>&,int ,int, vector<bool>&,int, int&);
int main(){
int q,a;
cin>>q;
int prod=1;
vector<int>power;
for(int i=0;i<=10;i++){
    power.push_back(prod);
    prod*=3;
}
vector<bool>visited(11,0);
for(int i=0;i<q;i++){
    int minVal=INT_MAX;
    cin>>a;
     backtracking(power,0,0,visited,a,minVal);
     cout << minVal <<endl;;

     
}




    return 0;
}

void backtracking(vector<int>&power, int sum, int first,vector<bool>&visited, int target, int& minVal){
    if(sum>=target){
        minVal=min(minVal,sum);
            return;
        
    }

        for(int i=first;i<power.size();i++){
            if(!visited[i]){
                visited[i]=true;
                sum+=power[i];
                backtracking(power,sum,i+1,visited,target,minVal);
                sum-=power[i];
                visited[i]=false;
            }
        }  

}



