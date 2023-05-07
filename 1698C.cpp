#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, m, a;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
       
        cin >> m;
        int sum = 0;
       
        vector<int> aVec;
       bool fg=true;
        for (int j = 0; j < m; j++)
        {

            cin >> a;
           aVec.push_back(a);


            if(m<=4)    sum += a;
            
             
        }

        if (m >= 5)
        {  
            bool flag=true;
            int cnt=0;
            int first=0;
            int second=0;
            for(int j=0;j<m;j++){
                if(aVec[j]!=0){
                    cnt++;
                    second=first;
                    first=aVec[j];
                    if(cnt>2){
                    flag=false;
                    cout<<"NO"<<endl;
                    break;
                    }
                }
            }
            if(!flag) continue;
            if (second == 0 || first == 0)
            {
                cout << "YES" << endl;
            }
            else if (first != 0 && second != 0 && first + second == 0)
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
        if (m == 3)
        {
            bool flag = false;
            for (int j = 0; j < 3; j++)
            {
                if (aVec[j] == sum)
                {
                    flag = true;
                }
            }
            if (flag)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        if (m == 4)
        {
            bool flag = true;
            unordered_set<int> aSet;
            for (int j = 0; j < 4; j++)
            {
                aSet.insert(aVec[j]);
            }
            for (int j = 0; j < 4; j++)
            {
                int val = sum - aVec[j];
                if (aSet.find(val) == aSet.end())
                {
                    flag = false;
                    cout << "NO" << endl;
                    break;
                }
            }
            if (flag) cout << "YES" << endl;
        }
    }

    return 0;
}