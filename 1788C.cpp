#include<bits/stdc++.h>

using namespace std;
int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        if(n%2==0){
            cout << "NO" <<endl;
            break;
        }
    
        cout << 1 <<" " <<2*n-1<<endl;
        int mid = 1+2*n;
        int small = mid-2*n/2+1;
        int large = mid+2*n/2-1;
        for(int j=large;j<=small;j+=2){
            int index = (small-j)/2+1;
            cout << j-(2*index+1) <<" " << 2*index+1  << endl;
        }
        
    }

    return 0;
}