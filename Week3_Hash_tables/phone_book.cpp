#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastIO ios::sync_with_stdio(false); cin.tie(false); cout.tie(false);
int main()
{
    //fastIO;
    int t;
    cin>>t;
    map<string,string>mp;
    while(t--)
    {
        string s;
        cin>>s;
        if(s=="add")
        {
            string num,name;
            cin>>num>>name;
            mp[num]=name;
        }
        else if(s=="find")
        {
            string number;
            cin>>number;
            if(mp.count(number)>0)
                cout<<mp[number]<<endl;
            else
                cout<<"not found\n";


        }
        else if(s=="del")
        {
            string number;
            cin>>number;
            mp[number]="not found";
        }
    }
    return 0;

}
