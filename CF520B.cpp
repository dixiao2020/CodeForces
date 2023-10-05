#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;

  vector<bool>visited(20001,false);

  visited[n]=true;
  queue<int>q;
  q.push(n);
  int dist=0;
  bool flag=false;
  while(!q.empty()){
    int nn = q.size();
    for(int i=0;i<nn;i++){
      int front = q.front();
      if(front==m){
        cout << dist<<endl;
        flag=true;
        break;
      }
      q.pop();
       if(front*2<=20000 && !visited[front*2]){
         visited[front*2]=true;
         q.push(front*2);
       }
      if(front-1>=1 && !visited[front-1]){
        visited[front-1]=true;
        q.push(front-1);
      }
    }
    if(flag) break;
    dist++;
  }

  
  return 0;
}