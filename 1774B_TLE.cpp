#include<bits/stdc++.h>

using namespace std;

int main(){

    int t,n,m,k,a;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
  
        scanf("%d%d%d",&n,&m,&k);
      
        if(m<k){
            printf("NO\n");
            continue;
        }
        int remainder =n%k;
        int quotient = n/k;
        bool flag=true;

        for(int j=0;j<m;j++){
            scanf("%d",&a);
           
            if((remainder==0 && a>quotient)||(remainder!=0 && a>quotient+1)){
                flag=false;
                
            }
        }
       
        if(flag){
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
        
      
            
        
    }
        
        
   

    return 0;
}