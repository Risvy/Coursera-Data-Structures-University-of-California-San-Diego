#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Threads
{
public:
    ll start_time;
    int thread_id;

    Threads()
    {
        this->start_time = 0;
    }
};
int rightchild(int i)
{
    return 2+ (2*i);
}

int leftchild(int i)
{
    return 1+ (2*i);
}


void shiftdown(int i, vector <Threads> &mythreads)
{
    int minindex = i;
    int left = leftchild(i);
    bool ok=0;
    if(left < static_cast<int>(mythreads.size()) && mythreads[left].start_time == mythreads[minindex].start_time)
    {
        int temp_original_id = mythreads[minindex].thread_id;
        int temp_left_id = mythreads[left].thread_id;
        ok=true;
        if(temp_original_id > temp_left_id)
            minindex = left;
    }

    else if(left < static_cast<int>(mythreads.size()) && mythreads[left].start_time < mythreads[minindex].start_time)
        minindex = left;

    int right = rightchild(i);

    if(right < static_cast<int>(mythreads.size()) && mythreads[right].start_time == mythreads[minindex].start_time)
    {
        int left_id = mythreads[minindex].thread_id;
        int right_id = mythreads[right].thread_id;

        if(left_id > right_id)
            minindex = right;
    }

    else if(right < static_cast<int>(mythreads.size()) && mythreads[right].start_time< mythreads[minindex].start_time)
        minindex = right;

    int flag=0;
    if(i!=minindex)  flag=1;
    if (flag)
    {
        swap(mythreads[i], mythreads[minindex]);
        shiftdown(minindex,mythreads);
    }
}

void ChangePriority(int i, ll new_priority, vector <Threads> &mythreads)
{
    mythreads[0].start_time = new_priority;

    shiftdown(0,mythreads);
}

void start(vector <ll > &jobs_list, vector <Threads> &mythreads)
{
    vector <pair <int,ll > > results;
    results.resize(jobs_list.size());

    for(int i=0; i<jobs_list.size(); i++)
    {
        results[i] = make_pair(mythreads[0].thread_id, mythreads[0].start_time);
        if(jobs_list[i] != 0)
            ChangePriority((int)0,mythreads[0].start_time + jobs_list[i], mythreads);
        char chh='\0';
    }

    for(int i=0; i<results.size(); i++)
        cout << results[i].first << " " << results[i].second << endl;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    vector <ll> jobs_list;
    jobs_list.resize(m);

    for(int i=0; i<m; i++)
        cin>>jobs_list[i];

    vector <Threads> mythreads;
    mythreads.resize(n);

    for(int i=0; i<n; i++)
        mythreads[i].thread_id = i;

    start(jobs_list,mythreads);
    return 0;
}
