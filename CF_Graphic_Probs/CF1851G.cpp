#include <bits/stdc++.h>
using namespace std;
int find(vector<int>&,int);
void uni(vector<int>&,vector<int>&,int,int);
static bool compare(vector<int>&, vector<int>&);
static bool comp(vector<int>&,vector<int>&);
int main() {

int t;
cin>>t;
int src,dst,m,q,start,end,n,h,energy;
  for(int i=0;i<t;i++){
    cin>>n>>m; // number of nodes and edges;
    vector<int>heights(n+1,0);
    for(int j=1;j<=n;j++){
      cin>>h;
      heights[j]=h;
    }
    vector<vector<int>>edges;
    for(int j=0;j<m;j++){
      cin>>src>>dst;
      edges.push_back({src,dst,max(heights[src],heights[dst])});
    }    
    sort(edges.begin(),edges.end(),comp);
    cin>>q;

   vector<vector<int>>queries;
    
    for(int j=0;j<q;j++){

      cin>>start>>end>>energy;
      queries.push_back({start,end,energy,j,heights[start]});

  }
    vector<int>parent(n+1,-1);
    vector<int>rank(n+1,1);
    sort(queries.begin(),queries.end(),compare);


    int left=0;
    int right = 0;


    vector<string>ans(q);
    while(right!=q){
      
      int total = heights[queries[right][0]]+queries[right][2];
      
      while(left<m && edges[left][2]<=total){
        uni(parent,rank,edges[left][0],edges[left][1]);
        left++;
      }

      int st = queries[right][0];
      int ed = queries[right][1];
      int index = queries[right][3];
      if(find(parent,st)==find(parent,ed)){
        ans[index]="YES";
      }
      else ans[index]="NO";
      right++;
    }

    
    for(int j=0;j<q;j++){
      cout << ans[j] <<endl;
    }
    cout<<endl;

    
    

  }
  return 0;

}
static bool compare(vector<int>&A, vector<int>&B){
    return A[4]+A[2]<B[4]+B[2];
}
int find(vector<int>&parent,int x){
  if(parent[x]==-1)return x;
  return find(parent,parent[x]);
}
  
void uni(vector<int>&parent, vector<int>&rank, int src, int dst){
  int x = find(parent,src);
  int y = find(parent,dst);
  if(x!=y){
    if(rank[x]>rank[y]){
      rank[x]+=rank[y];
      parent[y]=x;
    }
    else{
      rank[y]+=rank[x];
      parent[x]=y;
    }
  }
  
}
static bool comp(vector<int>&A,vector<int>&B){
   return A[2] < B[2];
}