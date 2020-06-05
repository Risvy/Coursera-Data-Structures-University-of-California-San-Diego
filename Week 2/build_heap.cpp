#include<bits/stdc++.h>
using namespace std;


class HeapBuilder
{
private:
    vector<int> data_;
    vector< pair<int, int> > swaps_;

    void WriteResponse() const
    {
        cout << swaps_.size() << "\n";
        for (int i = 0; i < swaps_.size(); ++i)
        {
            cout << swaps_[i].first << " " << swaps_[i].second << "\n";
        }
    }

    void ReadData()
    {
        int n;
        cin >> n;
        data_.resize(n);
        for(int i = 0; i < n; ++i)
            cin >> data_[i];
    }

    int left_value(int i)
    {
        return 2*i+1;
    }
    int right_value(int i)
    {
        return 2*i+2;
    }
    int parent(int n)
    {
        return floor((n-1)/2);
    }

    void go_down(int i)
    {
        int minIndex= i;
        int l= left_value(i);
        if(l<=data_.size()-1 and data_[l]<data_[minIndex] )
            minIndex=l;
        int r= right_value(i);
        if(r<=data_.size()-1 and data_[r]<data_[minIndex])
            minIndex=r;

        if(i!=minIndex)
        {
            swap(data_[i], data_[minIndex]);
            swaps_.push_back(make_pair(i,minIndex));
            go_down(minIndex);
        }
    }

    void GenerateSwaps()
    {
        swaps_.clear();
        bool ok=false;
        for (int i = (data_.size() -1)/2; i+1 !=0 ; i--)
            {
                go_down(i);
                ok=true;
            }
    }

public:
    void Solve()
    {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    HeapBuilder heap_builder;
    heap_builder.Solve();
    return 0;
}
