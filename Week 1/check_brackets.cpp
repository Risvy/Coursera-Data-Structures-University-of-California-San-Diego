#include<bits/stdc++.h>
using namespace std;
bool ok=false;
struct Bracket
{
    Bracket(char type, int position):
        type(type),
        position(position)
    {}
    bool Matchc(char c)
    {
        if(type=='[' and c==']')
            return true;
        if (type == '{' && c == '}')
        {
            return true;
        }
        if (type == '(' && c == ')')
        {
            return true;
        }
        return false;
    }
    char type;
    int position;

};

int main()
{
    string text;
    getline(cin,text);
    int ans=-1;
    stack<Bracket>stack_1;
    for (int position = 0; position < text.length(); ++position)
    {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{')
        {
            // Process opening bracket, write your code here
            Bracket *ch= new Bracket(next,position+1);
            stack_1.push(*ch);
        }

        if (next == ')' || next == ']' || next == '}')
        {
            // Process closing bracket, write your code here
            if(stack_1.empty())
            {
                //cout<<pos+1<<endl;
                ans=position+1;
                break;
            }
            else if(stack_1.top().Matchc(next))
                stack_1.pop();
            else
            {
                ans=position+1;
                ok=true;
                break;
            }

        }

    }

    if(stack_1.empty() and ans==-1) cout<<"Success"<<endl;
    else
    {
        if(!stack_1.empty() and ans==-1)
            ans=stack_1.top().position;

        cout<<ans<<endl;
    }

}
