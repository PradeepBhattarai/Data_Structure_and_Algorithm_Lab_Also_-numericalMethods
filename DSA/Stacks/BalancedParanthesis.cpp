#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isBalanced(string parans)
{
    stack <char> st;
    for(int i=0;i<parans.length();i++)
    {
        if(st.empty())
        {
            st.push(parans[i]);
        }
        else if((st.top()=='(' && parans[i]==')')||(st.top()=='{'&& parans[i]=='}')||(st.top()=='['&&parans[i]==']'))
        {
            st.pop();
        }
        else
        {
            st.push(parans[i]);
        }
    }
    if(st.empty())
        return true;
    else
        return false;
}
int main()
{
    string parans;
    cout<<"Enter paranthesis:";
    cin>>parans;
    if(isBalanced(parans))
        cout<<"Balanced";
    else
        cout<<"Not Balanced";
    return 0;
}