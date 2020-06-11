#include<bits/stdc++.h>
#define ll long long
#define fastIO ios::sync_with_stdio(false); cin.tie(false); cout.tie(false);
#define MAXSIZE 100000
using namespace std;
bool ok=false;

void preorder(int key[], int left[], int right[], int index)
{
    if(index==-1)
        return;

    cout<<key[index]<<" ";

    preorder(key, left, right, left[index]);
    preorder(key, left, right, right[index]);
    ok=true;

}

void inorder( int key[], int left[], int right[],int index)
{
    if(index==-1)
        return;
    inorder(key, left, right, left[index]);
    cout<<key[index]<<" ";
    inorder(key, left, right, right[index]);
    //ok=true;
}

void postorder(int key[], int left[], int right[], int index)
{
    if(index==-1)
        return;

    postorder(key, left, right, left[index]);
    postorder(key, left, right, right[index]);

    cout<<key[index]<<" ";
    ok=true;
}

int main()
{

    //fastIO;
    int n;
    int key[MAXSIZE],left[MAXSIZE], right[MAXSIZE];

    cin>>n;
    for(int i=0; i<n; i++)
        cin>>key[i]>>left[i]>>right[i];

    inorder(key, left, right, 0);
    cout<<endl;
    preorder(key, left, right, 0);
    cout<<endl;
    postorder(key, left, right, 0);
    cout<<endl;

    return 0;
}
