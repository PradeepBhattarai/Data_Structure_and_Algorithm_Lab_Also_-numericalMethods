#include<iostream>
#include<string>
#include<stack>
using namespace std;
int precedenceof(char c)
{
    if(c=='^')
        return 3;
    if(c=='*'||c=='/'||c=='%')
        return 2;
    if(c=='+'||c=='-')
        return 1;
    else{
        return -1;
    }
}
string InfixToPostfix(string infix)
{
    stack<char> st;
    string result;
    for(int i=0;i<infix.length();i++)
    {
        if((infix[i]>='a' && infix[i]<='z')||(infix[i]>='0' && infix[i]<='9'))
        {
            result+=infix[i];
        }
        else if(infix[i]=='(')
        {
            st.push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while(st.top()!='(')
            {
                result+=st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && precedenceof(infix[i])<=precedenceof(st.top()))
            {
                result+=st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }
    while(!st.empty())
    {
        result+=st.top();
        st.pop();
    }
    return result;
}
int main()
{
    string infix;
    cout<<"Enter the infix expression: ";
    cin>>infix;
    cout<<InfixToPostfix(infix);

    return 0;
}