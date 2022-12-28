#include<iostream>
#include<stack>
using namespace std;
int EvaluatePostfix(string postfix)
{
    stack<int> st;

    for(int i=0;i<postfix.length();i++)
    {
        //for single digits operands
        if(isdigit(postfix[i]))
        {
            st.push(postfix[i]-'0');
        }
        else
        {
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();
            switch(postfix[i])
            {
                case '+':
                    st.push(op2+op1);
                    break;
                case '-':
                    st.push(op2-op1);
                    break;
                case '*':
                    st.push(op2*op1);
                    break;
                case '/':
                    st.push(op2/op1);
                    break;
                case '^':
                    st.push(op2^op1);
                    break;
                default:
                    cout<<"invalid expression";
                    break;
            }
            
        }
    }
    return st.top();
}
int main()
{
    string postfix;
    cout<<"Enter postfix expression:";
    cin>>postfix;
    cout<<EvaluatePostfix(postfix);
    return 0;
}