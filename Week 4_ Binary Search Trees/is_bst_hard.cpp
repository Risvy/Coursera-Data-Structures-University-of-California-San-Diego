#include<bits/stdc++.h>
#define ll long long
#define fastIO ios::sync_with_stdio(false); cin.tie(false); cout.tie(false);
#define MAX_SZ 100000

//using namespace std;
//due to ambiguous problem,using namespace previous is not used

bool ok=false;
int key[MAX_SZ] = {0};
int left_child[MAX_SZ] = {-1};
int right_child[MAX_SZ] = {-1};

int small[MAX_SZ]= {INT_MAX},large[MAX_SZ]= {INT_MIN};

void print_ans(int result)
{
    if(result)
        std::cout<<"CORRECT"<<std::endl;
    else
        std::cout<<"INCORRECT"<<std::endl;
}

int is_bst(int intdex)
{
    if(intdex==-1)
        return true;

    ///Check left_child
    if (left_child[intdex] == -1)
        small[intdex] = key[intdex];

    else
    {
        if(!is_bst(left_child[intdex]))
            return false;
        if(key[intdex]<=large[left_child[intdex]])
            return false;

        small[intdex]=small[left_child[intdex]];
        ok=false;
    }
    ///Check right_child
    if(right_child[intdex]==-1)
        large[intdex]=key[intdex];

    else
    {
        if(!is_bst(right_child[intdex]))
            return false;
        if(key[intdex]>small[right_child[intdex]]) ///The only difference between hard and easy version is this line
            return false;
        large[intdex]=large[right_child[intdex]];
        ok=true;
    }
    return true;
}

int main()
{
    int n;
    std::cin>>n;
    for(int i=0; i<n; i++)
        std::cin>>key[i]>>left_child[i]>>right_child[i];
    print_ans(is_bst(0));
    return 0;
}
