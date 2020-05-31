#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastIO ios::sync_with_stdio(false); cin.tie(false); cout.tie(false);
const ll MAX = (ll) 1e5+9;
vector<vector<int>> adj(MAX);
bool ok=false;
int dfs(int r)
{
    if(adj[r].size()==0) return true;
    else
    {
        int mx=0;
        for(int i=0;i<adj[r].size();i++)
        {
            int j= adj[r][i];
            mx=max(mx,dfs(j));
        }
        return 1+mx;
    }
}

int main()
{
    //fastIO;
    ll n, r;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]==-1)
            r=i;
        else adj[a[i]].push_back(i);
        ok=true;
    }
    cout<<dfs(r)<<endl;
}
