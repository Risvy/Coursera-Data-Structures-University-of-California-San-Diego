#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastIO ios::sync_with_stdio(false); cin.tie(false); cout.tie(false);
const ll maxn = (ll) 1e5+9;
vector<vector<int>> adj(maxn);
bool ok=false;
int main()
{
    //fastIO;
    //FastIO turned off due to coursera c++ compiler couldn't recognize.
    int S,n,j=0,t=0;
    cin>>S>>n;
    queue<pair<int, pair<int, int>>> q;
    vector<pair<int,pair<int,int>>>v(n);
    vector<int>res(n);
    for(int i=0; i<n; i++)
    {
        int j,k;
        cin>>j>>k;
        v[i]=make_pair(i,make_pair(j,k));
    }

    while(j<n and j<S)
    {
        q.push(v[j]);
        j++;
    }

    while(!q.empty())
    {
        ok=true;
        int stk= max(t,q.front().second.first);
        t=stk + q.front().second.second;
        res[q.front().first]=stk;
        q.pop();
        while(q.size()<S and j<n)
        {
            if(v[j].second.first<t)
                res[j++]=-1;
            else
                q.push(v[j++]);

        }
    }
    for(int i=0; i<n; i++)
        cout<<res[i]<<endl;

}
