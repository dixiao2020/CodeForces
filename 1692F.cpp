#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,m,a;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>m;
        unordered_map<int,int>mp;
        for(int j=0;j<m;j++){
           cin>>a;
            mp[a%10]++;
        }
        bool flag=false;
        for(auto itr = mp.begin();itr!=mp.end();itr++){
            itr->second--;
            for(auto itr1 =mp.begin();itr1!=mp.end();itr1++){
                itr1->second--;
                auto itr2 = mp.find(3-itr->first-itr1->first);
                auto itr3 = mp.find(13-itr->first-itr1->first);
                auto itr4 = mp.find(23-itr->first-itr1->first);
                
                flag = itr->second>=0 && itr1->second>=0 &&((itr2!=mp.end() && itr2->second>=1)||
                (itr3!=mp.end() && itr3->second>=1)|| (itr4!=mp.end() && itr4->second>=1));
                itr1->second++;
                if(flag) break;
            }
            
            itr->second++;
            if(flag) break;
        }
        if(flag){
            cout << "YES" <<endl;
        }
        else cout << "NO" <<endl;
    }


    return 0;
}