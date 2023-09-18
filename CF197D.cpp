#include <bits/stdc++.h>
using namespace std;
vector<int>Tree;
void update(long long, long long, long long , int, long long, int);
int query(long long,long long,long long,long long,long long,int);
int main() {
  int flag=0;
  int n;
  cin>>n;
  if(n%2==0) flag=1;
  int nn = (int)pow(2,n); // number of nodes
  
  Tree = vector<int>(4*nn,0); // allocate memory for tree
  
  int m;
  cin>>m; // number ofquerries
  int a;
  for(int i=0;i<nn;i++){
    cin>>a;
    update(0,nn-1,i,a,0,flag);
  }
// for(int i=0;i<4*nn;i++){
//    cout << Tree[i] <<endl;
//  }
  
  
  int pos,value;
  for(int i=0;i<m;i++){
    cin>>pos;
    cin>>value;
    update(0,nn-1,pos-1,value,0,flag);
    cout << Tree[0] <<endl;
  }
  

  return 0;
}






  void update(long long tl, long long tr, long long pos, int val, long long index, int flag){
          if(tl>pos|| tr<pos) return;
        if(tl==pos && tl==tr){
          Tree[index]=val;
          return;
        }
    long long mid = tl+(tr-tl)/2;
          update(tl, mid,pos,val,index*2+1,1- flag);
          update(mid+1,tr,pos,val,index*2+2,1-flag);
        if(flag==0){
          Tree[index]=Tree[index*2+1]|Tree[index*2+2];
        }
    else Tree[index]=Tree[index*2+1]^Tree[index*2+2];
  }
 // [tl,tr] [ql,qr] [tl,tr]
// [ql,[tl,tr],qr]
  int query(long long tl, long long tr, long long ql, long long qr, long long index, int flag){
     if(tr<ql || qr<tl) return 0;

    if(ql<=tl && tr<=qr){
      return Tree[index];
    }
    long long mid =tl+(tr-tl)/2;
    if(flag==0){
      return query(tl,mid,ql,qr,index*2+1,1-flag)|query(mid+1,tr,ql,qr,index*2+2,1-flag);
    }
        else{
          return query(tl,mid,ql,qr,index*2+1,1-flag)^query(mid+1,tr,ql,qr,index*2+2,1-flag);
        }
    
  }

  
