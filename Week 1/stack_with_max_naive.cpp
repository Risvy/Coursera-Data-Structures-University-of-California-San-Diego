#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
bool ok=false;
class stacks
{
	vector<pair<int,int> > elements;
	int top;

public:
	stacks()
	{
		top=-1;
	}
	bool empty()
	{
		return top==-1;
	}
	void push(int e)
	{
		if(empty())
		{
			elements.push_back(make_pair(e,e));
			top=0;
		}
		else
		{
			ok=true;
			int mx=max(e,elements[top].second);
			//check
			elements.push_back(make_pair(e,mx));
			top++;
		}
	}
	void pop()
	{
	    elements.pop_back();
	    top--;
	}

	int mx()
	{
	    return elements[top].second;
	}
};

int main()
{	//cin.tie(true);
	int n;
	cin>>n;
	stacks s;
	string str;
	int e,i;
	for(i=0;i<n;++i)
	{
		cin>>str;
		if(str=="push")
		{
			cin>>e;
			s.push(e);
		}
		else if(str=="pop")
			s.pop();
		else
			cout<<s.mx()<<endl;
	}
	return 0;
}
