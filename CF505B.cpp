#include <bits/stdc++.h>
using namespace std;
void uni(int, int, vector<int>&,vector<int>&);
int find(int, vector<int>&);
int main() {
  vector<int>parent(10201,-1);
  vector<int>rank(10202,1);
int n,m;
  cin>>n>>m;
  int src,dst,color;
  
  
  for(int i=0;i<m;i++){
    cin>>src>>dst>>color;
    int sc = 100*color+src;
    int dt = 100*color+dst;
    uni(sc,dt,parent,rank);
  }

   int q;
  cin>>q;
  int a,b;
  for(int i=0;i<q;i++){
    cin>>a>>b;
    int ans=0;
    for(int j=1;j<=100;j++){
      int st = 100*j+a;
      int ed = 100*j+b;
      if(find(st,parent)==find(ed,parent)) ans++;
    }
    cout << ans<<endl;
  }

  return 0;
}

int find(int x, vector<int>&parent){
  if(parent[x]==-1) return x;
  return find(parent[x],parent);
}




void uni(int src, int dst, vector<int>&parent, vector<int>&rank){
   int x = find(src,parent);
  int y = find(dst,parent);
  if(x!=y){
    if(rank[x]>=rank[y]){
      rank[x]+=rank[y];
      parent[y]=x;
    }
    else{
      rank[y]+=rank[x];
      parent[x]=y;
    }
  }
  
}

